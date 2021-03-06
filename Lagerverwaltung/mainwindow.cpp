#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include "database.h"
#include "stdint.h"

#include <QMessageBox>
#include <QFile>
#include <QFontDatabase>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Barcodeschrift hinzufügen, um Barcodes grafisch anzuzeigen
    QFontDatabase BarcodeFontDatabase;
    BarcodeFontDatabase.addApplicationFont("c39hrp24dhtt.ttf");
    ui->LabelBarcodeNum->setFont(BarcodeFontDatabase.font("c39hrp24dhtt","Any",30));

    // Spaltenbreite der Zellen einstellen
    ui->tableWidget->setColumnWidth(0,COL_WIDTH_BARCODE);
    ui->tableWidget->setColumnWidth(1,COL_WIDTH_QUANTITY);

    // Anzeige der Statusleiste auf "Disconnected" einstellen
    ui->statusBar->showMessage(tr("Disconnected"));

    // Initialisierungen
    readingMode = ModeNormal;
    serial = new QSerialPort(this);
    settings = new SettingsDialog;
    database = new Cdatabase();

    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);

    initActionsConnections();

    // Verbindungen zum Hardware-Slot herstellen
    connect(serial, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(handleError(QSerialPort::SerialPortError)));

    connect(serial, SIGNAL(readyRead()), this, SLOT(readData()));

    // aktuellen Datenbankinhalt anzeigen
    database->showDatabase(ui->tableWidget);
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
    RxBuffer(serial->readLine(255));
}

void MainWindow::RxBuffer(QString rx)
{
    static QString buffer;

    buffer += rx;

    if (buffer.endsWith('\n'))
    {
        buffer.chop(1);                         // delete 1 last char of string ('\n')
        ui->LabelBarcodeNum->setText(buffer);
        lastBarcode = buffer;
        if (readingMode == ModeAdd)
            on_ButtonAdd_clicked();
        else if (readingMode == ModeDelete)
            on_ButtonDelete_clicked();
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
    if(!lastBarcode.isEmpty())
    {
        database->itemAdd(lastBarcode, 1);
    }
    on_ButtonShow_clicked();
    ui->LabelState->setText("Article added");
}

void MainWindow::on_ButtonDelete_clicked()
{
    database->itemDelete(lastBarcode, 1);
    on_ButtonShow_clicked();
    ui->LabelState->setText("Article deleted");
}

void MainWindow::on_ButtonShow_clicked()
{
    ui->LabelState->setText("Loading database...");

    database->showDatabase(ui->tableWidget);

    ui->LabelState->setText("Database successfully loaded!");
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    QString clickedBarcode;

    if (ui->tableWidget->item(row,0) == NULL)
    {
        // leeres Feld ausgewählt -> Item hinzufügen
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(0));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(0));
        ui->tableWidget->insertRow(row+1);
    }

    clickedBarcode = ui->tableWidget->item(row,0)->text();      // geklickten Barcode speichern

    ui->LabelState->setText("Ready");

    if (column != 0)
    {
        ui->tableWidget->setCurrentCell(row,0);                 // Zellenauswahl auf Barcode versetzen
    }

    ui->LabelBarcodeNum->setText(clickedBarcode);               // geklickten Barcode anzeigen
    lastBarcode = clickedBarcode;                               // und als letzten Barcode festlegen

}

void MainWindow::on_ButtonBatchAdd_clicked()
{
    if (readingMode != ModeAdd)
        readingMode = ModeAdd;
    else
        readingMode = ModeNormal;
    cleanup();
}

void MainWindow::on_ButtonBatchDelete_clicked()
{
    if (readingMode != ModeDelete)
        readingMode = ModeDelete;
    else
        readingMode = ModeNormal;
    cleanup();
}

void MainWindow::cleanup()
{
    switch(readingMode)
    {
        case ModeNormal:
        {
            ui->ButtonAdd->show();
            ui->ButtonDelete->show();
            ui->ButtonBatchAdd->setText("Add a batch");
            ui->ButtonBatchDelete->setText("Delete a batch");
        }; break;
        case ModeAdd:
        {
            ui->ButtonAdd->hide();
            ui->ButtonDelete->hide();
            ui->ButtonBatchAdd->setText("go to normal mode");
            ui->ButtonBatchDelete->setText("Delete a batch");
        }; break;
        case ModeDelete:
        {
            ui->ButtonAdd->hide();
            ui->ButtonDelete->hide();
            ui->ButtonBatchAdd->setText("Add a batch");
            ui->ButtonBatchDelete->setText("go to normal mode");
        }; break;
    }
}
