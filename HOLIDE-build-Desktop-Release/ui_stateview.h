/********************************************************************************
** Form generated from reading UI file 'stateview.ui'
**
** Created: Fri Jan 4 19:47:49 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEVIEW_H
#define UI_STATEVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBoxPhase;
    QFrame *line;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPlainTextEdit *textEditInputThrms;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *textEditProofThrms;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPlainTextEdit *textEditConclusionThrms;
    QFrame *line_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QPlainTextEdit *textEditHaskell;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(549, 614);
        verticalLayout_2 = new QVBoxLayout(Form);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        lineEditName = new QLineEdit(Form);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        verticalLayout->addWidget(lineEditName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        comboBoxPhase = new QComboBox(Form);
        comboBoxPhase->setObjectName(QString::fromUtf8("comboBoxPhase"));

        verticalLayout->addWidget(comboBoxPhase);

        line = new QFrame(Form);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEditInputThrms = new QPlainTextEdit(groupBox);
        textEditInputThrms->setObjectName(QString::fromUtf8("textEditInputThrms"));

        gridLayout->addWidget(textEditInputThrms, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(Form);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textEditProofThrms = new QPlainTextEdit(groupBox_2);
        textEditProofThrms->setObjectName(QString::fromUtf8("textEditProofThrms"));

        gridLayout_2->addWidget(textEditProofThrms, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Form);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textEditConclusionThrms = new QPlainTextEdit(groupBox_3);
        textEditConclusionThrms->setObjectName(QString::fromUtf8("textEditConclusionThrms"));

        gridLayout_3->addWidget(textEditConclusionThrms, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        line_2 = new QFrame(Form);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        groupBox_4 = new QGroupBox(Form);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textEditHaskell = new QPlainTextEdit(groupBox_4);
        textEditHaskell->setObjectName(QString::fromUtf8("textEditHaskell"));

        gridLayout_4->addWidget(textEditHaskell, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Form", "Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Form", "Phase", 0, QApplication::UnicodeUTF8));
        comboBoxPhase->clear();
        comboBoxPhase->insertItems(0, QStringList()
         << QApplication::translate("Form", "Quantum Key Distrubition", 0, QApplication::UnicodeUTF8)
        );
        groupBox->setTitle(QApplication::translate("Form", "Input Theorems", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Form", "Inference Rule", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("Form", "Conclusion", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("Form", "Haskell", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEVIEW_H
