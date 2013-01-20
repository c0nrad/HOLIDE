#include <QTextEdit>
#include "projectview.h"
#include "ui_projectview.h"

ProjectView::ProjectView(Project *p, QWidget *parent) :
    QWidget(parent), mProject(p)
{
    setupUi(this);
    this->labelProjectName->setText(mProject->getProjectName());
    this->lineEditAuthors->setText(mProject->getAuthors().join("; "));
    this->textEditDescription->setPlainText(mProject->getProjectDescription().join("\n"));
    this->textEditPrincipals->setPlainText(mProject->getPrincipals().join("; "));
    this->textEditActions->setPlainText(mProject->getActions().join("; "));
}

ProjectView::~ProjectView()
{

}

QStringList ProjectView::getProjectDescription() const {
    return this->textEditDescription->document()->toPlainText().split("\n");
}

QStringList ProjectView::getPrincipals() const {
    return this->textEditPrincipals->document()->toPlainText().split(";");
}

QStringList ProjectView::getActions() const {
    return this->textEditActions->document()->toPlainText().split(";");
}

QStringList ProjectView::getAuthors() const {
    return this->lineEditAuthors->text().split(";");
}
