#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include "database.h"

#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->statusBar->showMessage(tr("Disconnected"));

    serial = new QSerialPort(this);

    settings = new SettingsDialog;

    database = new Cdatabase();

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);

    initActionsConnections();

    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

}

MainWindow::~MainWindow()
{
    if(serial->isOpen())
        closeSerialPort();

    delete ui;
    delete serial;
    delete settings;
    delete database;
}

void MainWindow::openSerialPort()
{
    SettingsDialog::Settings COM_settings = settings->settings();
    serial->setPortName(COM_settings.name);
    serial->setBaudRate(COM_settings.baudRate);
    serial->setDataBits(COM_settings.dataBits);
    serial->setParity(COM_settings.parity);
    serial->setStopBits(COM_settings.stopBits);
    serial->setFlowControl(COM_settings.flowControl);

    if(serial->open(QIODevice::ReadWrite))
    {
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        ui->statusBar->showMessage(tr("Connected to %1 : %2, %3, %4, %5, %6").arg(COM_settings.name).arg(COM_settings.stringBaudRate).arg(COM_settings.stringDataBits).arg(COM_settings.stringParity).arg(COM_settings.stringStopBits).arg(COM_settings.stringFlowControl));
    }
    else
    {
        QMessageBox::critical(this, tr("ERROR"), serial->errorString());

        ui->statusBar->showMessage(tr("open error"));
    }


}

void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    ui->statusBar->showMessage(tr("Disconnected"));
}

void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}

void MainWindow::readData()
{
    QString text;

    text = serial->readLine(255);

    RxBuffer(text);
}

void MainWindow::RxBuffer(QString rx)
{
    static QString buffer;

    buffer += rx;

    if (buffer.endsWith('\n'))
    {
        buffer.chop(1);     // delete 1 last char of string ('\n')
        ui->LabelBarcodeNum->setText(buffer);
        lastBarcode = buffer;
        buffer.clear();
    }
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError)
    {
        QMessageBox::critical(this, tr("critical Error"), serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
}

void MainWindow::on_ButtonAdd_clicked()
{
    // ui->tableWidget->setItem(0, 0, new QTableWidgetItem(lastBarcode));
    if(!lastBarcode.isEmpty())
    {
        database->itemAdd(lastBarcode, 1);
    }
}

void MainWindow::on_ButtonDelete_clicked()
{
    database->itemDelete(lastBarcode, 1);
}
