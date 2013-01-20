#ifndef STATEVIEW_H
#define STATEVIEW_H

#include <QWidget>
#include "ui_stateview.h"

class StateView : public QWidget, public Ui::Form
{
    Q_OBJECT

public:
    explicit StateView(QWidget *parent = 0);
    StateView(QString name, QString phase, QStringList inputThms, QStringList proofThms, QStringList conclusionThms, QStringList haskell);
    ~StateView();

    QString getName() const;
    QString getPhase() const;
    QStringList getInputThms() const;
    QStringList getProofThms() const;
    QStringList getConclusionThms() const;
    QStringList getHaskell() const;
};

#endif // STATEVIEW_H

