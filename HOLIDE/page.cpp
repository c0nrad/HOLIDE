#include "page.h"

Page::Page(QObject *parent) :
    QTextEdit(0)
{
}

void Page::setFileName(const QString &fileName) {
    mFileName = fileName;
}

void Page::setFilePath(const QString &filePath) {
    mFilePath = filePath;
}

QString Page::getFileName() {
    return mFileName;
}

QString Page::getFilePath() {
    return mFilePath;
}
