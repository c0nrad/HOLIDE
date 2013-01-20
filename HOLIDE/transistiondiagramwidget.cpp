#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDropEvent>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QGraphicsItem>
#include "transistiondiagramwidget.h"
#include "transistionstate.h"
#include "link.h"
#include "project.h"

const int SCENE_HEIGHT = 1000;
const int SCENE_WIDTH = 1000;

TransistionDiagramWidget::TransistionDiagramWidget(QWidget *parent) :
    QGraphicsView(parent) {
    setupScene();
}

TransistionDiagramWidget::TransistionDiagramWidget(Project *p, QWidget *parent) :
    QGraphicsView(parent) {
    mProject = p;
    setupScene();
}

void TransistionDiagramWidget::setupScene() {
    mScene = new QGraphicsScene(0, 0, SCENE_WIDTH, SCENE_HEIGHT, this);

    setScene(mScene);
    setDragMode(QGraphicsView::RubberBandDrag);
    setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    setAlignment(Qt::AlignTop | Qt::AlignLeft);

    this->drawDots();

    mMinZ = 0;
    mMaxZ = 0;

    mSequenceNumber = 1;

    setWindowTitle("State Transistion Diagram");
}

void TransistionDiagramWidget::addState(const QString& name) {
    qDebug() << "\n[*] TransistionDiagramWidget::addState";

    qDebug() << "[+] New State:" << name;
    TransistionState *state = new TransistionState;
    state->setName(name);

    // TODO: Check if point is on the grid
    state->setPos(QPoint(100 * mSequenceNumber, 100));
    mSequenceNumber++;
    mScene->addItem(state);

    mScene->clearSelection();
    state->setSelected(true);

    mStates.insert(state);
}

void TransistionDiagramWidget::addState() {
    addState(tr("State %1").arg(mSequenceNumber));
}

void TransistionDiagramWidget::removeSelected() {
    qDebug() << "\n[*] TransistionDiagramWidget::removeSelected";
    QList<QGraphicsItem *> selected = mScene->selectedItems();

    if (selected.size() == 0) {
        qDebug() << "[-] No items selected";
        return;
    }

    foreach (QGraphicsItem *item, selected) {
        if (isTransistionState(item)) {
            qDebug() << "[+] Deleting Transistion State";
            TransistionState *state = dynamic_cast<TransistionState*>(item);
            removeState(state);
        } else if (isLink(item)) {
            qDebug() << "[+] Deleting Link";
            Link *link = dynamic_cast<Link*>(item);
            removeLink(link);
        }
    }
}

void TransistionDiagramWidget::removeState(TransistionState *state) {
    mScene->removeItem(state);
    mStates.remove(state);
    mScene->update();
}

void TransistionDiagramWidget::removeLink(Link* link) {
    mScene->removeItem(link);
    mScene->update();
}

void TransistionDiagramWidget::addLink() {}

bool TransistionDiagramWidget::isLink(QGraphicsItem *item) {
    Link *link = dynamic_cast<Link*> (item);
    return link != NULL;
}

bool TransistionDiagramWidget::isTransistionState(QGraphicsItem *item) {
    TransistionState *state = dynamic_cast<TransistionState*>(item);
    return state != NULL;
}

void TransistionDiagramWidget::drawDots() {
    for (int x = 0; x < 1600; x += 100) {
        for (int y = 0; y < 1000; y += 100) {
            QGraphicsEllipseItem* circle = mScene->addEllipse(x, y, 5, 5, QPen(QColor(Qt::darkRed), 0), QBrush(Qt::darkRed));
            circle->setFlag(QGraphicsItem::ItemIsSelectable);
        }
    }
}

void TransistionDiagramWidget::updatePositions() {
    foreach(TransistionState* state, mStates) {
        int x = state->x();
        int y = state->y();

        int newX = ((x + 50) / 100) * 100;
        int newY = ((y + 50) / 100) * 100;
        state->setPos(newX, newY);
    }
}

void TransistionDiagramWidget::zoomIn() {
    qDebug() << "\n[*] TransistionDiagramWidget::zoomIn";
    scale(1.2, 1.2);
}

void TransistionDiagramWidget::zoomOut() {
    qDebug() << "\n[*] TransistionDiagramWidget::zoomOut";
    scale(.8, .8);
}

void TransistionDiagramWidget::mouseReleaseEvent(QMouseEvent *event) {
    QGraphicsView::mouseReleaseEvent(event);
    updatePositions();
}

void TransistionDiagramWidget::saveStates() {
    qDebug() << "\n[*] TransistionDiagramWidget::saveStates";
    QSet<TransistionState*> states = mStates;

    foreach (TransistionState* state, states) {
        state->save();
    }
}
