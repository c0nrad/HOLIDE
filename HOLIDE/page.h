#ifndef PAGE_H
#define PAGE_H

#include <QTextEdit>

class Page : public QTextEdit
{
    Q_OBJECT
public:
    explicit Page(QObject *parent = 0);

    void setFileName(const QString& fileName);
    void setFilePath(const QString& fileName);
    QString getFileName();
    QString getFilePath();
    
signals:
    
public slots:;

private:
    QString mFileName;
    QString mFilePath;
    
};

#endif // PAGE_H
