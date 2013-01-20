#ifndef HOLWIDGET_H
#define HOLWIDGET_H

#include <QTextEdit>

class QProcess;

class HOLWidget : public QTextEdit
{
    Q_OBJECT
public:
    explicit HOLWidget(QWidget *parent = 0);

    void writeToHOL(QString line);
    void turnOffPrettyPrint();
    void turnOffUnicode();

signals:

public slots:
    void readStandardError();
    void readStandardOut();    
    void finished(int exitStatus);

    void restart();
    void showTypes();
    void showTypesVerbose();
    void showAssumptions();
    void showNumericalTypes();

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    void startHOL();
    QProcess *mHOLProcess;

};

#endif // HOLWIDGET_H
