#ifndef HOLMAKEWIDGET_H
#define HOLMAKEWIDGET_H

#include <QTextEdit>

class QProcess;

class HOLMakeWidget : public QTextEdit
{
    Q_OBJECT
public:
    explicit HOLMakeWidget(QWidget *parent = 0);

signals:

public slots:
    void readStandardError();
    void readStandardOut();
    void finished(int exitStatus);

private:
    void startHolmake();
    void startHolmakeCleanAll();

    QProcess *mHolmakeProcess;

};

#endif // HOLMAKEWIDGET_H
