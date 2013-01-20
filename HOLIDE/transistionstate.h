#ifndef TRANSISTIONSTATE_H
#define TRANSISTIONSTATE_H

#include <QGraphicsItem>
#include <QSet>
#include <QObject>

class Link;

class TransistionState : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    TransistionState();
    ~TransistionState();

    void setName(const QString& name);
    QString getName() const;
    void setTextColor(const QColor& color);
    QColor getTextColor() const;
    void setBackgroundColor(const QColor& color);
    QColor getBackgroundColor() const;
    void setOutlineColor(const QColor &color);
    QColor getOutlineColor() const;

    void addLink(Link *link);
    void removeLink(Link *link);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void save();
    void read();

signals:
    void doubleClick();
    void pieceMoved();

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QString fileName();

    QRectF outlineRect() const;
    int roundness(double size) const;

    /* Information */
    QString mName;
    QString mPhase;
    QStringList mInputThrms;
    QStringList mAssumptions;
    QStringList mLogic;
    QStringList mConclusion;
    QStringList mHaskell;

    /* Node Properties */
    QSet<Link *> mLinks;
    QColor mTextColor;
    QColor mBackgroundColor;
    QColor mOutlineColor;
    bool mIsHovered;

};

#endif // TRANSISTIONSTATE_H
