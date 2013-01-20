#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H


#include <QWidget>
#include "ui_projectview.h"
#include "project.h"

class ProjectView : public QWidget, Ui::ProjectView
{
    Q_OBJECT

public:
    explicit ProjectView(Project *p, QWidget *parent = 0);
    ~ProjectView();

    QStringList getProjectDescription() const;
    QStringList getPrincipals() const;
    QStringList getActions() const;
    QStringList getAuthors() const;

signals:
    void save();

private:
    Project *mProject;
};

#endif // PROJECTVIEW_H
