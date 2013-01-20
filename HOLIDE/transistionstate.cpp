#include <QApplication>
#include <QFontMetricsF>
#include <QPainter>
#include <QStyle>
#include <QMessageBox>
#include <QPainterPath>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneDragDropEvent>
#include <QDebug>
#include <QXmlStreamReader>

#include "transistionstate.h"
#include "link.h"
#include "stateview.h"

TransistionState::TransistionState() {
    mTextColor = Qt::darkGreen;
    mOutlineColor = Qt::darkBlue;
    mBackgroundColor = Qt::white;
    mIsHovered = false;

    setFlags(ItemIsMovable | ItemIsSelectable);

    setAcceptHoverEvents(true);
    this->setAcceptDrops(true);
}

TransistionState::~TransistionState() {
    foreach (Link* l, mLinks)
        delete l;
}

void TransistionState::setName(const QString &name) {
    mName = name;
}

QString TransistionState::getName() const {
    return mName;
}

void TransistionState::setTextColor(const QColor &color) {
    mTextColor = color;
}

QColor TransistionState::getTextColor() const {
    return mTextColor;
}

void TransistionState::setBackgroundColor(const QColor &color) {
    mBackgroundColor = color;
}

QColor TransistionState::getBackgroundColor() const {
    return mBackgroundColor;
}


void TransistionState::setOutlineColor(const QColor &color) {
    mOutlineColor = color;
}

QColor TransistionState::getOutlineColor() const {
    return mOutlineColor;
}

void TransistionState::addLink(Link *link) {
    mLinks.insert(link);
}

void TransistionState::removeLink(Link *link) {
    mLinks.remove(link);
}

QRectF TransistionState::outlineRect() const {
    const int SIZE = 80;
    //const int PADDING = 8;
    //const int EXTRA_HEIGHT = 10;
    //QFontMetricsF metrics = qApp->font();
    //QRectF rect = metrics.boundingRect(mName);
    //rect.adjust(-PADDING, -PADDING - EXTRA_HEIGHT, PADDING, PADDING + EXTRA_HEIGHT);
    QRectF constSize(-SIZE/2, -SIZE/2, SIZE, SIZE);

    if (mIsHovered)
        constSize.adjust(-5, -5, 5, 5);
    return constSize;
}

QRectF TransistionState::boundingRect() const {
    const int MARGIN = 6;
    return outlineRect().adjusted(-MARGIN, -MARGIN, MARGIN, MARGIN);
}

QPainterPath TransistionState::shape() const {
    QRectF rect = outlineRect();

    QPainterPath path;
    path.addRoundRect(rect, roundness(rect.width()), roundness(rect.height()));
    return path;
}

void TransistionState::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(widget);
    QPen pen(mOutlineColor);
    if (option->state & QStyle::State_Selected) {
        pen.setStyle(Qt::DotLine);
        pen.setWidth(2);
    }

    painter->setPen(pen);
    painter->setBrush(mBackgroundColor);

    QRectF rect = outlineRect();
    painter->drawRoundedRect(rect, roundness(rect.width()), roundness(rect.height()));

    painter->setPen(mTextColor);
    painter->drawText(rect, Qt::AlignCenter | Qt::TextWordWrap, mName);
}

QVariant TransistionState::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionHasChanged) {
        QPointF newPos = value.toPointF();
        qDebug() << newPos;
        foreach (Link *link, mLinks)
            link->trackNodes();
    }
    return QGraphicsItem::itemChange(change, value);
}

void TransistionState::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event) {
    Q_UNUSED(event);

    emit doubleClick();

    //StateView *dialog = new StateView(mName, mPhase, mInputThrms, mLogic, mConclusion, mHaskell);
    // dialog->show();
    //if (dialog->exec()) {
    //   qDebug() << "Saving information!";
    //    mName = dialog->getName();
    //    mPhase = dialog->getPhase();
    //    mInputThrms = dialog->getInputThms();
    //    mLogic = dialog->getProofThms();
    //    mConclusion = dialog->getConclusionThms();
    //    mHaskell = dialog->getHaskell();
    //    save();
   // }
}

int TransistionState::roundness(double size) const {
    const int DIAMETER = 12;
    return 50 * DIAMETER / int(size);
}

void TransistionState::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);
    mIsHovered = true;
    update();
}

void TransistionState::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    Q_UNUSED(event);
    mIsHovered = false;
    update();
}

void TransistionState::save() {
    qDebug() << "\n[*] TransistionState::save";

    qDebug() << "[+] Saving:" << mName << "to file:" << fileName();
    QFile file(fileName());
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "[-] Error: Cannot write file" <<
                    qPrintable(fileName()) <<": " <<
                    qPrintable(file.errorString());
        return;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("TransistionState");
    stream.writeTextElement("Name", mName);
    stream.writeTextElement("XPos", QString::number(this->pos().x()));
    stream.writeTextElement("YPos", QString::number(this->pos().y()));
    stream.writeTextElement("Phase", mPhase);
    stream.writeTextElement("InputTheorems", mInputThrms.join("\n"));
    stream.writeTextElement("InferenceLogic", mLogic.join("\n"));
    stream.writeTextElement("Conclusion", mConclusion.join("\n"));
    stream.writeTextElement("Haskell", mHaskell.join("\n"));
    stream.writeEndElement();
    stream.writeEndDocument();

    file.close();
    if (file.error()) {
        qDebug() << "[-] Error: Cannot write file" <<
                    qPrintable(fileName()) <<": " <<
                    qPrintable(file.errorString());
        return;
    }
}

void TransistionState::read() {
    qDebug() << "\n[*] TransistionState::read";

    qDebug() << "[+] Reading:" << mName << "to file:" << fileName();
    QFile file(fileName());
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "[-] Error: Cannot write file" <<
                    qPrintable(fileName()) <<": " <<
                    qPrintable(file.errorString());
        return;
    }

    QXmlStreamReader reader(&file);
    reader.readNextStartElement();
    int xPos = 100, yPos = 100;
    while (!reader.atEnd()) {
        if (reader.isStartDocument()) {
            /* Do nothing */
        } else if (reader.isStartElement()) {

            if (reader.name().toString() == "Name") {
                reader.readNext();
                mName = reader.text().toString();
            } else if (reader.name().toString() == "XPos") {
                reader.readNext();
                xPos = reader.text().toString().toInt();
            } else if (reader.name().toString() == "YPos") {
                reader.readNext();
                yPos = reader.text().toString().toInt();
            } else if (reader.name().toString() == "Phase") {
                reader.readNext();
                mPhase = reader.text().toString();
            } else if (reader.name().toString() == "InputTheorems") {
                reader.readNext();
                mInputThrms = reader.text().toString().split("\n");
            } else if (reader.name().toString() == "InferenceLogic") {
                reader.readNext();
                mLogic = reader.text().toString().split("\n");
            } else if (reader.name().toString() == "Conclusion") {
                reader.readNext();
                mConclusion = reader.text().toString().split("\n");
            } else if (reader.name().toString() == "Haskell") {
                reader.readNext();
                mHaskell = reader.text().toString().split("\n");
            } else if (reader.name().toString() == "TransistionState") {
                // Do nothing!
            } else
                qDebug() << "[-] Unkown name: " << reader.name().toString() << reader.text().toString();
        }
        reader.readNext();
    }
    this->setPos(xPos, yPos);

    file.close();
    if (reader.hasError()) {
        qDebug() <<"[-] Error: Failed to parse file " <<
                   qPrintable(fileName()) << ": " <<
                   qPrintable(reader.errorString());
        return;
    } else if (file.error() != QFile::NoError) {
        qDebug() << "[-] Error: Cannot read file" <<
                    qPrintable(fileName()) <<": " <<
                    qPrintable(file.errorString());
        return;
    }
    return;
}

QString TransistionState::fileName()  {
    QString temp = mName;
    return temp.remove(" ") + ".xml";
}

