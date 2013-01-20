#ifndef LINK_H
#define LINK_H

#include <QGraphicsLineItem>

class TransistionState;

class Link : public QGraphicsLineItem
{
public:
    Link(TransistionState *from, TransistionState *to);
    ~Link();

    TransistionState *fromState() const;
    TransistionState *toState() const;

    void setColor(const QColor &color);
    QColor getColor() const;

    void trackNodes();

private:
    TransistionState* mFromState;
    TransistionState* mToState;
};

#endif // LINK_H
