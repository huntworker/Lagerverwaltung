/*! \file database.h
 *  \brief Header file for class Cdatabase.
 *
 *  Cdatabase creates or uses an existing database in .csv
 *  format to store a string and its ammount in stock.
 */

#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QTableWidget>


/*! \class Cdatabase
 *  \brief A small product database based on .csv file.
 *
 *  Opens or creates a database file in the current folder.
 *  You can add or delete items by giving a string to
 *  identify the product and a quantiy to add or delete.
 *  You can also display the content of the whole database.
 */
class Cdatabase
{
public:
    /**
     * \fn constructor.
     * \brief empty function.
     */
    Cdatabase();

    /**
     * \fn destructor.
     * \brief empty function.
     */
    ~Cdatabase();

    /**
     * \fn itemAdd.
     * \brief Adds an item to database.
     * If the item already exists, the quantity will be
     * increased by @param quantity. If not, the item will
     * be added at the end of the database.
     * @param   barcode    String to identify the product
     * @param   quantity   gives the ammount of products to add
     * @return  void
     */
    void itemAdd(QString barcode, int quantity);

    /**
     * \fn itemDelete.
     * \brief Deletes an Item from database.
     * If the quantity of the searched product is less or equal to
     * the quantity in the database, the entry will be deleted.
     * @param   barcode    String to identify the product
     * @param   quantity   gives the ammount of products to delete
     * @return  void
     */
    void itemDelete(QString barcode, int quantity);

    /**
     * \fn showDatabase.
     * \brief Sets entries in the given QTableWidget to show all entries
     * of the database.
     * @param   table   QTableWidget, in which the database will be shown.
     * @return  void
     */
    void showDatabase(QTableWidget* table);


private:
    /**
     * \var file
     * Is used to save the database file.
     * type: pointer to QFile
     */
    QFile* file;

    /**
     * private variable tempFile
     * If the database has to be edited, each entry will
     * be edited and saved into a new file.
     * type: pointer to QFile
     */
    QFile* tempFile;

    /**
     * private variable tempFileStream
     * Is used to read and write to @tempFile.
     * type: pointer to QTextStream
     */
    QTextStream* tempFileStream;

    /**
     * private variable FileStream
     * Is used to read and write to @File.
     * type: pointer to QTextStream
     */
    QTextStream* FileStream;

};

#endif // DATABASE_H
