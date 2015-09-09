#define COL_WIDTH_BARCODE   160
#define COL_WIDTH_QUANTITY  80

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtSerialPort/QSerialPort>

namespace Ui {
class MainWindow;
}

class SettingsDialog;
class Cdatabase;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

    void on_ButtonAdd_clicked();

    void on_ButtonDelete_clicked();

    void on_ButtonShow_clicked();

    void on_tableWidget_cellClicked(int row, int column);

private:
    void initActionsConnections();
    void RxBuffer(QString);
    QString lastBarcode;

    Ui::MainWindow *ui;
    QSerialPort *serial;
    SettingsDialog *settings;
    Cdatabase *database;
};

#endif // MAINWINDOW_H
