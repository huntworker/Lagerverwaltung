/*! \file mainwindow.h
 *  \brief Header file for class MainWindow.
 *
 *  MainWindow initializes all settings regarding the
 *  main user interface window. It also controls the connection
 *  to the barcode scanner via RS232 interface.
 */

/*! \def COL_WIDTH_BARCODE
 *  \brief A macro that defines the width of column Barcode in
 *  database user interface window.
 */
#define COL_WIDTH_BARCODE   160

/*! \def COL_WIDTH_QUANTITY
 *  \brief A macro that defines the width of column Quantity in
 *  database user interface window.
 */
#define COL_WIDTH_QUANTITY  80

/**
 * \enum batchMode.
 * \brief Batch mode to scan and store a huge amount of Products
 * in a short time.
 */
enum batchMode
{
    ModeNormal, /**< a scanned product can be added or deleted from database. */
    ModeAdd,    /**< every product being scanned will be added to database. */
    ModeDelete  /**< every product being scanned will be deleted from database. */
};

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>

namespace Ui {
class MainWindow;
}

class SettingsDialog;
class Cdatabase;

/*! \class MainWindow
 *  \brief controls all IOs and sets up the main user interface.
 *
 *  This class gets all user actions and shows data on MainWindow.
 *  It also controls and sets up the serial port.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * \fn MainWindow.
     * \brief Constructor of class MainWindow.
     * Uses a special font to illustrate the read barcode.
     * Creates objects for serial port, database, settings.
     * Initializes user interface and serial port.
     * Shows database in Table.
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * \fn ~MainWindow.
     * \brief Destructor of class MainWindow.
     * Closes serial port, deletes dynamically created objects
     * of user interface, serial port, settings and database.
     */
    ~MainWindow();

private slots:
    /**
     * \fn openSerialPort.
     * \brief Sets up serial port.
     * Takes all serial settings from SettingsDialog window and
     * configures serial port. If the connection succeeds, all settings
     * appear in the status bar. Else, the user gets an error message.
     * @return  void
     */
    void openSerialPort();

    /**
     * \fn closeSerialPort.
     * \brief closes serial port.
     * If serial port is open, it will be closed.
     * In all cases, it sets up the user interface.
     * @return  void
     */
    void closeSerialPort();

    /**
     * \fn writeData.
     * \brief writes data to serial port.
     * @param   &data  reference to data to write
     * @return  void
     */
    void writeData(const QByteArray &data);

    /**
     * \fn readData.
     * \brief Gets data from serial port.
     * All data will be given to function RxBuffer to
     * store them local.
     * @return  void
     */
    void readData();

    /**
     * \fn handleError.
     * \brief is being called, if an error with serial port occurs.
     * If an error with serial port occurs, the user will be informed
     * with an error string in a message box.
     * @param   error
     * @return  void
     */
    void handleError(QSerialPort::SerialPortError error);

    /**
     * \fn on_ButtonAdd_clicked.
     * \brief is being called, if the user clicks on the "add to database"
     * button.
     * Stores the current barcode in database and shows the new database table.
     * @return  void
     */
    void on_ButtonAdd_clicked();

    /**
     * \fn on_ButtonDelete_clicked.
     * \brief is being called, if the user clicks on the "delete from database"
     * button.
     * Deletes the current barcode from database and shows the new database table.
     * @return  void
     */
    void on_ButtonDelete_clicked();

    /**
     * \fn on_ButtonShow_clicked.
     * \brief is being called, if the user clicks on the "show database"
     * button.
     * Shows the current database table.
     * @return  void
     */
    void on_ButtonShow_clicked();

    /**
     * \fn on_tableWidget_cellClicked.
     * \brief is being called, if the user clicks in the database table.
     * If the clicked cell is empty, the list will be extended by one entry.
     * The clicked barcode will be applied as current barcode and displayed
     * in the barcode label.
     * @param   row     specifies the clicked row
     * @param   column  specifies the clicked column
     * @return  void
     */
    void on_tableWidget_cellClicked(int row, int column);

    /**
     * \fn on_ButtonBatchAdd_clicked.
     * \brief is being called, if the user clicks on the "BatchAdd"
     * button.
     * Sets the current reading mode to batchAdd and calls function cleanup.
     * @return  void
     */
    void on_ButtonBatchAdd_clicked();

    /**
     * \fn on_ButtonBatchDelete_clicked.
     * \brief is being called, if the user clicks on the "BatchDelete"
     * button.
     * Sets the current reading mode to batchDelete and calls function cleanup.
     * @return  void
     */
    void on_ButtonBatchDelete_clicked();

private:
    /**
     * \fn initActionsConnections.
     * \brief connects menu buttons to corresponding function.
     * @return  void
     */
    void initActionsConnections();

    /**
     * \fn RxBuffer.
     * \brief is being called, if data will be received via serial port.
     * Collects all data until char '\n' is received. If so, the received
     * barcode will be stored and the receive buffer will be cleared.
     * @param   QString  last received data
     * @return  void
     */
    void RxBuffer(QString);

    /**
     * \fn cleanup.
     * \brief sets the user interface depending on the actual reading mode.
     * @return  void
     */
    void cleanup();

    /**
     * \var lastBarcode.
     * \brief stores the last scanned barcode.
     */
    QString lastBarcode;

    /**
     * \var readingMode.
     * \brief defines the current reading mode.
     * @see batchMode
     */
    batchMode readingMode;

    /**
     * \var ui.
     * \brief Pointer to MainWindow type.
     * Address will be given in constructor of MainWindow.
     */
    Ui::MainWindow *ui;

    /**
     * \var serial.
     * \brief Pointer to QSerialPort type.
     * Address will be given in constructor of MainWindow.
     */
    QSerialPort *serial;

    /**
     * \var setting.
     * \brief Pointer to SettingsDialog type.
     * Address will be given in constructor of MainWindow.
     */
    SettingsDialog *settings;

    /**
     * \var database.
     * \brief Pointer to Cdatabase type.
     * Address will be given in constructor of MainWindow.
     */
    Cdatabase *database;
};

#endif // MAINWINDOW_H
