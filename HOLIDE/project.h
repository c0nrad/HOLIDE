#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>
#include <QString>
#include <QSet>
#include <QStringList>
#include <QDir>

class Phase;
class TransistionState;

class Project : public QObject
{
    Q_OBJECT

public:
    Project();
    Project(QString fileName);

    QString getProjectName() const;
    QStringList getAuthors() const;
    QStringList getProjectDescription() const;
    QStringList getPrincipals() const;
    QStringList getActions() const;

    QDir mTopLevel;
    QDir mXmlFolder;

public slots:
    //void saveAll();
    void saveProjectFile();
  //  void openProjectFile();
    void openProject(QString fileName);


    //void addState();
    //void addState(const QString& name);

    void setProjectName(QString const& name);
    void setProjectDescription(QStringList const& description);
    void setAuthors(QStringList const& authors);
    void setActions(QStringList const& actions);
    void setPrincipals(QStringList const& principals);
signals:

private:
    void cleanAll();
    QString fileName();

    QString mProjectName;
    QStringList mAuthors;
    QStringList mProjectDescription;
    QStringList mPrincipals;
    QStringList mActions;

    QSet<Phase *> mPhases;
    QSet<TransistionState *> mStates;

    /* Links */

    /* File Paths */
    //QString HOLMAKE_PATH=;
    //HASKELL...
    // CWD...
    // HOLPRO path...
};

#endif // PROJECT_H
