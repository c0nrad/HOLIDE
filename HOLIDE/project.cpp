#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDebug>
#include "project.h"
#include "transistionstate.h"
#include "phase.h"

Project::Project()
{
}

Project::Project(QString fileName) {
    openProject(fileName);
}

QString Project::getProjectName() const {
    return mProjectName;
}
QStringList Project::getAuthors() const {
    return mAuthors;
}
QStringList Project::getProjectDescription() const {
    return mProjectDescription;
}
QStringList Project::getPrincipals() const {
    return mPrincipals;
}
QStringList Project::getActions() const {
    return mActions;
}

void Project::setProjectName(QString const& name) {
    mProjectName = name;
}

void Project::setProjectDescription(QStringList const& description) {
    mProjectDescription = description;
}

void Project::setAuthors(QStringList const& authors) {
    mAuthors = authors;
}

void Project::setActions(QStringList const& actions) {
    mActions = actions;
}

void Project::setPrincipals(QStringList const& principals) {
    mPrincipals = principals;
}

void Project::openProject(QString fileName) {
    qDebug() << "Project::openProject: " << fileName;

    cleanAll();

    qDebug() << "[+] Opening file";
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug () << "[-] Error cannot read file" <<
                     qPrintable(fileName) << ":" <<
                     qPrintable(file.errorString());
        return;
    }

    QXmlStreamReader reader(&file);
    reader.readNextStartElement();
    while (!reader.atEnd()) {
        if (reader.isStartDocument()) {
            /* Do nothing */
        } else if (reader.isStartElement()) {
            if (reader.name().toString() == "Name") {
                reader.readNext();
                mProjectName = reader.text().toString();
            } else if (reader.name().toString() == "Authors") {
                reader.readNext();
                mAuthors = reader.text().toString().split(";");
            } else if (reader.name().toString() == "Description") {
                reader.readNext();
                mProjectDescription = reader.text().toString().split(";");
            } else if (reader.name().toString() == "Principals") {
                reader.readNext();
                mPrincipals = reader.text().toString().split(";");
            } else if (reader.name().toString() == "Actions") {
                reader.readNext();
                mActions = reader.text().toString().split(";");
            } else {
                qDebug() << "[-] Unkown name: " << reader.name().toString() << reader.text().toString();
            }
        }
        reader.readNext();
    }

    qDebug() << "[+] Done Reading Project File";
    file.close();
    if (reader.hasError()) {
        qDebug() <<"[-] Error: Failed to parse file " <<
                   qPrintable(fileName) << ": " <<
                   qPrintable(reader.errorString());
        return;
    } else if (file.error() != QFile::NoError) {
        qDebug() << "[-] Error: Cannot read file" <<
                    qPrintable(fileName) <<": " <<
                    qPrintable(file.errorString());
        return;
    }
    return;

}

void Project::saveProjectFile() {
    QFile file(fileName());
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        qDebug() << "Error: Cannot write file" <<
                    qPrintable(fileName()) <<": " <<
                    qPrintable(file.errorString());
        return;
    }

    QXmlStreamWriter stream(&file);
    stream.setAutoFormatting(true);
    stream.writeStartDocument();
    stream.writeStartElement("Project");
    stream.writeTextElement("Name", mProjectName);
    stream.writeTextElement("Authors", mAuthors.join(";"));
    stream.writeTextElement("Description", mProjectDescription.join(";"));
    stream.writeTextElement("Principals", mPrincipals.join(";"));
    stream.writeTextElement("Actions", mActions.join(";"));
    stream.writeEndElement();
    stream.writeEndDocument();

    file.close();
    if (file.error()) {
        qDebug() << "Error: Cannot write file" <<
                    qPrintable(fileName()) <<": " <<
                    qPrintable(file.errorString());
        return;
    }
}

QString Project::fileName()  {
    QString temp = mProjectName;
    return temp.remove(" ") + ".holpro";
}

void Project::cleanAll() {
    qDebug() << "\n[*] Project::cleanAll";
    foreach (Phase *p, mPhases) {
        delete p;
    }
    mPhases.clear();

    foreach (TransistionState* state, mStates) {
        delete state;
    }
    mStates.clear();
}
