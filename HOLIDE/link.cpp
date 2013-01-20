#include <QApplication>
#include <QPen>
#include "link.h"
#include "transistionstate.h"

Link::Link(TransistionState *from, TransistionState *to) {
    mFromState = from;
    mToState = to;

    mFromState->addLink(this);
    mToState->addLink(this);
    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);

    setColor(Qt::darkRed);
    trackNodes();
}

Link::~Link() {
    mFromState->removeLink(this);
    mToState->removeLink(this);
}

void Link::setColor(const QColor &color) {
    setPen(QPen(color, 1.0));
}

void Link::trackNodes() {
    setLine(QLineF(mFromState->pos(), mToState->pos()));
}
