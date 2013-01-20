/********************************************************************************
** Form generated from reading UI file 'projectview.ui'
**
** Created: Fri Jan 4 19:47:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTVIEW_H
#define UI_PROJECTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectView
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *labelProjectName;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEditAuthors;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *textEditDescription;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *textEditPrincipals;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QPlainTextEdit *textEditActions;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_3;
    QListWidget *listWidgetPhases;

    void setupUi(QWidget *ProjectView)
    {
        if (ProjectView->objectName().isEmpty())
            ProjectView->setObjectName(QString::fromUtf8("ProjectView"));
        ProjectView->resize(647, 600);
        verticalLayout_2 = new QVBoxLayout(ProjectView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelProjectName = new QLabel(ProjectView);
        labelProjectName->setObjectName(QString::fromUtf8("labelProjectName"));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelProjectName->setFont(font);

        verticalLayout_2->addWidget(labelProjectName);

        groupBox = new QGroupBox(ProjectView);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditAuthors = new QLineEdit(groupBox);
        lineEditAuthors->setObjectName(QString::fromUtf8("lineEditAuthors"));

        gridLayout->addWidget(lineEditAuthors, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(ProjectView);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEditDescription = new QPlainTextEdit(groupBox_2);
        textEditDescription->setObjectName(QString::fromUtf8("textEditDescription"));

        gridLayout_2->addWidget(textEditDescription, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(ProjectView);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        textEditPrincipals = new QPlainTextEdit(groupBox_3);
        textEditPrincipals->setObjectName(QString::fromUtf8("textEditPrincipals"));

        verticalLayout->addWidget(textEditPrincipals);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        textEditActions = new QPlainTextEdit(groupBox_3);
        textEditActions->setObjectName(QString::fromUtf8("textEditActions"));

        verticalLayout->addWidget(textEditActions);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(ProjectView);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_3 = new QGridLayout(groupBox_5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        listWidgetPhases = new QListWidget(groupBox_5);
        new QListWidgetItem(listWidgetPhases);
        new QListWidgetItem(listWidgetPhases);
        listWidgetPhases->setObjectName(QString::fromUtf8("listWidgetPhases"));

        gridLayout_3->addWidget(listWidgetPhases, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_5);


        retranslateUi(ProjectView);

        QMetaObject::connectSlotsByName(ProjectView);
    } // setupUi

    void retranslateUi(QWidget *ProjectView)
    {
        ProjectView->setWindowTitle(QApplication::translate("ProjectView", "Form", 0, QApplication::UnicodeUTF8));
        labelProjectName->setText(QApplication::translate("ProjectView", "Project Name", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ProjectView", "Author(s):", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ProjectView", "Description", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ProjectView", "Global Proposistions", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ProjectView", "Principals:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ProjectView", "Actions:", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("ProjectView", "Phases", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidgetPhases->isSortingEnabled();
        listWidgetPhases->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidgetPhases->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("ProjectView", "Quantum Key Distribution", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidgetPhases->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("ProjectView", "LOL", 0, QApplication::UnicodeUTF8));
        listWidgetPhases->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class ProjectView: public Ui_ProjectView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTVIEW_H
