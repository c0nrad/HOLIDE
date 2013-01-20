#include <QProcess>
#include <iostream>
#include <QDebug>
#include <QKeyEvent>
#include "holmakewidget.h"

const QString HOLMAKE_PATH = "/opt/HOL/bin/Holmake";

HOLMakeWidget::HOLMakeWidget(QWidget *parent) :
    QTextEdit(parent)
{
    startHolmakeCleanAll();
    startHolmake();
}

void HOLMakeWidget::startHolmake() {
    mHolmakeProcess = new QProcess;
    append(tr("Running Holmake... "));

    mHolmakeProcess->start(HOLMAKE_PATH);

    this->setReadOnly(true);

    QObject::connect(mHolmakeProcess, SIGNAL(readyReadStandardError()), this, SLOT(readStandardError()));
    QObject::connect(mHolmakeProcess, SIGNAL(readyReadStandardOutput()), this, SLOT(readStandardOut()));
    QObject::connect(mHolmakeProcess, SIGNAL(finished(int)), this, SLOT(finished(int)));
}

void HOLMakeWidget::startHolmakeCleanAll() {
    QProcess *cleanAll = new QProcess;

    insertPlainText(tr("Running Holmake cleanAll..."));
    cleanAll->start(HOLMAKE_PATH + " cleanAll");
    cleanAll->waitForFinished();
    insertPlainText(tr(" Done!\n"));
}

void HOLMakeWidget::readStandardError() {
    append( QString(mHolmakeProcess->readAllStandardError()));
}

void HOLMakeWidget::readStandardOut() {
    append(mHolmakeProcess->readAllStandardOutput());
}

void HOLMakeWidget::finished(int status) {
    Q_UNUSED(status);
    insertPlainText(tr("Done!"));
}


