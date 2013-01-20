#ifndef TRANSISTIONDIAGRAMWIDGET_H
#define TRANSISTIONDIAGRAMWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QSet>

class QGraphicsScene;
class TransistionState;
class Link;
class Project;

class TransistionDiagramWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit TransistionDiagramWidget(QWidget *parent = 0);
    TransistionDiagramWidget(Project *p, QWidget *parent = 0);

signals:

public slots:
    void addState();
    void addState(const QString& name);
    void removeSelected();
    void removeState(TransistionState* state);
    void removeLink(Link* link);
    void addLink();

    void drawDots();
    void updatePositions();

    void saveStates();

    void zoomIn();
    void zoomOut();

protected:
    void mouseReleaseEvent(QMouseEvent *event);

private:
    bool isTransistionState(QGraphicsItem *item);
    bool isLink(QGraphicsItem *item);

    void setupScene();

    QGraphicsScene *mScene;
    QSet<TransistionState *> mStates;

    Project *mProject;

    int mMinZ;
    int mMaxZ;
    int mSequenceNumber;

};

#endif // TRANSISTIONDIAGRAMWIDGET_H
