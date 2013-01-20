#include <QProcess>
#include <iostream>
#include <QDebug>
#include <QKeyEvent>
#include "holwidget.h"

const QString HOL_PATH = "/opt/HOL/bin/hol";

HOLWidget::HOLWidget(QWidget *parent) :
    QTextEdit(parent)
{
    startHOL();
}

void HOLWidget::startHOL() {
    mHOLProcess = new QProcess;
    mHOLProcess->start(HOL_PATH);

    turnOffPrettyPrint();

    QObject::connect(mHOLProcess, SIGNAL(readyReadStandardError()), this, SLOT(readStandardError()));
    QObject::connect(mHOLProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readStandardOut()));
    QObject::connect(mHOLProcess, SIGNAL(finished(int)), this, SLOT(finished(int)));
}

void HOLWidget::readStandardError() {
    append( QString(mHOLProcess->readAllStandardError()));
}

void HOLWidget::readStandardOut() {
    append(mHOLProcess->readAllStandardOutput());
}

void HOLWidget::finished(int status) {
    Q_UNUSED(status);
    std::cout << "Process has finished!";
}

void HOLWidget::writeToHOL(QString line) {
    //qDebug() << "Writing to HOL: " << line;
    mHOLProcess->write(line.toLatin1());
}

void HOLWidget::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
            QString document = toPlainText();
            int lastDash = document.lastIndexOf("- ");
            QString holInput = document.right(document.size() - lastDash - 1);
            writeToHOL(holInput + '\n');
            break;
    }

    QTextEdit::keyPressEvent(e);
}

void HOLWidget::turnOffPrettyPrint() {
    const QString PAYLOAD = "Parse.current_backend := PPBackEnd.raw_terminal;\n";
    writeToHOL(PAYLOAD);
}

void HOLWidget::restart() {
    mHOLProcess->kill();
    delete mHOLProcess;
    clear();
    startHOL();
}

void HOLWidget::showTypes() {
    static bool on = false;
    QString PAYLOAD;
    if (on)
        PAYLOAD = "Globals.show_types := false;\n";
    else
        PAYLOAD = "Globals.show_types := true;\n";

    on = !on;

    writeToHOL(PAYLOAD);
}

void HOLWidget::showAssumptions() {
    static bool on = false;
    QString PAYLOAD;
    if (on)
        PAYLOAD = "Globals.show_assums := false;\n";
    else
        PAYLOAD = "Globals.show_assums := true;\n";

    on = !on;

    writeToHOL(PAYLOAD);;
}

void HOLWidget::showTypesVerbose() {
    static bool on = false;
    QString PAYLOAD;
    if (on)
        PAYLOAD = "Globals.show_types_verbosely := false;\n";
    else
        PAYLOAD = "Globals.show_types_verbosely := true;\n";

    on = !on;

    writeToHOL(PAYLOAD);
}

void HOLWidget::showNumericalTypes() {
    static bool on = false;
    QString PAYLOAD;
    if (on)
        PAYLOAD = "Globals.show_numeral_types := false;\n";
    else
        PAYLOAD = "Globals.show_numeral_types := true;\n";

    on = !on;

    writeToHOL(PAYLOAD);
}

void HOLWidget::turnOffUnicode() {
    QString PAYLOAD = "set_trace \"Unicode\" 0;\n";
    writeToHOL(PAYLOAD);
}


