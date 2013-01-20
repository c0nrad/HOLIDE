#include "stateview.h"
#include "ui_stateview.h"

StateView::StateView(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

StateView::StateView(QString name, QString phase, QStringList inputThms, QStringList proofThms, QStringList conclusionThms, QStringList haskell) {
    setupUi(this);
    this->lineEditName->setText(name);
    this->comboBoxPhase->addItem(phase);
    this->textEditInputThrms->insertPlainText(inputThms.join("\n"));
    this->textEditProofThrms->insertPlainText(proofThms.join("\n"));
    this->textEditConclusionThrms->insertPlainText(conclusionThms.join("\n"));
    this->textEditHaskell->insertPlainText(haskell.join("\n"));
}

StateView::~StateView()
{
}

QString StateView::getName() const {
    return this->lineEditName->text();
}

QString StateView::getPhase() const {
    return this->comboBoxPhase->currentText();
}

QStringList StateView::getInputThms() const {
    return this->textEditInputThrms->document()->toPlainText().split("\n");
}

QStringList StateView::getProofThms() const {
    return this->textEditProofThrms->document()->toPlainText().split("\n");
}

QStringList StateView::getConclusionThms() const {
    return this->textEditConclusionThrms->document()->toPlainText().split("\n");
}

QStringList StateView::getHaskell() const {
    return this->textEditHaskell->document()->toPlainText().split("\n");
}
