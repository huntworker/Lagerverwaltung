#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Cdatabase
{
public:
    Cdatabase();
    ~Cdatabase();
    void itemAdd(QString barcode, int quantity);
    void itemDelete(QString barcode, int quantity);


private:
    //Datenbankdatei
    //struct article
    //{
    //    int barcode;
    //    int quantity;
    //};
    //
    //article* file;

    QFile* file;
    QFile* tempFile;
    QTextStream* tempFileStream;
    QTextStream* FileStream;

};

#endif // DATABASE_H
