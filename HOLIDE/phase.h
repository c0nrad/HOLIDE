#ifndef PHASE_H
#define PHASE_H

#include <QString>
#include <QColor>

class Phase
{
public:
    Phase();

private:
    QString mName;
    QStringList mDescription;
    QColor mColor;
    QStringList mPrincipals;
    QStringList mActions;
};

#endif // PHASE_H
