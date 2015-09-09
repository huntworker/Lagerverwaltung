#include <qstring>
#include <iostream>
using namespace std;
#include <stdint.h>

#include "database.h"

Cdatabase::Cdatabase()
{
    //file = new QFile("database.csv");
    //tempFile = new QFile("tempDatabase.csv");
    //QFile file("test.txt");
    //if(file->open(QIODevice::ReadWrite))
    //{
    //    // Öffnen erfolgreich
    //}
    //if(tempFile->open(QIODevice::ReadWrite))
    //    // öffnen erfolgreich
    //
    //FileStream = new QTextStream(file);
    //tempFileStream = new QTextStream(tempFile);
}

Cdatabase::~Cdatabase()
{
    //file->close();
    //tempFile->close();
    //tempFile->remove();
    //delete file;
    //delete FileStream;
    //delete tempFileStream;
    //delete tempFile;

    // Hier sollte jetzt ein Kommentar von Mathias stehen.
}

void Cdatabase::itemAdd(QString barcode, int quantity)
{
    QString inBarcode = "";
    QString inQuantity = 0;
    bool barcodeFound = false;
    int newQuantity = 0;

    file = new QFile("database.csv");
    tempFile = new QFile("tempDatabase.csv");

    file->open(QIODevice::ReadWrite);
    tempFile->open(QIODevice::ReadWrite);

    FileStream = new QTextStream(file);
    tempFileStream = new QTextStream(tempFile);


    do
    {
        QString inBuffer = file->readLine();

        inBuffer.chop(1);                       // delete '\n'
        if (inBuffer.isEmpty())
        {
            *tempFileStream << "Barcode,Quantity" << endl;
        }
        else
        {
            QStringList bufferList = inBuffer.split(',');
            inBarcode = bufferList.at(0);
            inQuantity = bufferList.at(1);
        }
        if (inBarcode.compare(inBarcode, barcode) == 0)
        {
            newQuantity = quantity + inQuantity.toInt();
            *tempFileStream << inBarcode << ',' << newQuantity << endl;
            barcodeFound = true;
        }
        else
        {
            *tempFileStream << inBuffer << endl;
        }

    } while (!file->atEnd());

    if (!barcodeFound)
        *tempFileStream << barcode << ',' << quantity << endl;

    //cout << "Barcode: " << inBarcode << ", Quantity: " << inQuantity << endl;

    file->close();
    tempFile->close();
    file->remove();
    tempFile->rename("database.csv");

    delete file;
    delete FileStream;
    delete tempFileStream;
    delete tempFile;
}

void Cdatabase::itemDelete(QString barcode, int quantity)
{
    QString inBarcode = "";
    QString inQuantity = 0;
    int newQuantity = 0;
    bool barcodeFound = false;

    file = new QFile("database.csv");
    tempFile = new QFile("tempDatabase.csv");

    file->open(QIODevice::ReadWrite);
    tempFile->open(QIODevice::ReadWrite);

    FileStream = new QTextStream(file);
    tempFileStream = new QTextStream(tempFile);

    do
    {
        QString inBuffer = file->readLine();

        inBuffer.chop(1);                       // delete '\n'
        if (inBuffer.isEmpty())
        {
            *tempFileStream << "Barcode,Quantity";
        }
        else
        {
            QStringList bufferList = inBuffer.split(',');
            inBarcode = bufferList.at(0);
            inQuantity = bufferList.at(1);
        }
        if (inBarcode.compare(inBarcode, barcode) == 0)
        {
            if (quantity < inQuantity.toInt())
            {
                newQuantity = inQuantity.toInt() - quantity;
                *tempFileStream << inBarcode << ',' << newQuantity << endl;
            }
            else
            {
                quantity = 0;       //Todo: fehlermeldung
            }
            barcodeFound = true;
        }
        else
        {
            *tempFileStream << inBuffer << endl;
        }

    } while (!file->atEnd());

    if (!barcodeFound)
        // Fehler: versuche Artikel zu löschen, welches nicht vorhanden

    //cout << "Barcode: " << inBarcode << ", Quantity: " << inQuantity << endl;

    file->close();
    tempFile->close();
    file->remove();
    tempFile->rename("database.csv");

    delete file;
    delete FileStream;
    delete tempFileStream;
    delete tempFile;
}
