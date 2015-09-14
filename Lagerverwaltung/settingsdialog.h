/*! \file settingsdialog.h
 *  \brief Header filer for class SettingsDialog.
 *
 *  SettingsDialog is beeing called by clicking the settings button
 *  on MainWindow. In SettingsDialog you can choose the serial port
 *  to communicate with the barcode scanner.
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QtSerialPort/QSerialPort>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE

namespace Ui {
class SettingsDialog;
}

class QIntValidator;

QT_END_NAMESPACE


/*! \class SettingDialog
 *  \brief sets up an window to make settings for serial port.
 */
class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * \struct Settings.
     * \brief Stores all settings needed to initialize the communication
     * to the barcode scanner.
     */
    struct Settings {
        QString name;                           /**< Name as string. */
        qint32 baudRate;                        /**< Baudrate as number. */
        QString stringBaudRate;                 /**< Baudrate as string. */
        QSerialPort::DataBits dataBits;         /**< Number of data bits. */
        QString stringDataBits;                 /**< Number of data bits as string. */
        QSerialPort::Parity parity;             /**< Parity information. */
        QString stringParity;                   /**< Parity as string. */
        QSerialPort::StopBits stopBits;         /**< Stop bits. */
        QString stringStopBits;                 /**< Stop bits as string. */
        QSerialPort::FlowControl flowControl;   /**< Flow control. */
        QString stringFlowControl;              /**< Flow control as string. */
    };

    /**
     * \fn SettingsDialog.
     * \brief Constructor of class SettingsDialog.
     * sets up an user interface to choose settings.
     */
    explicit SettingsDialog(QWidget *parent = 0);

    /**
     * \fn ~SettingsDialog.
     * \brief Destructor of class SettingsDialog.
     *Cleanup.
     */
    ~SettingsDialog();

    /**
     * \fn settings.
     * \brief Returns actual settings.
     * @return Settings actual settings.
     */
    Settings settings() const;

private slots:
    /**
     * \fn showPortInfo.
     * \brief Displays information to selected COM port.
     * @param  idx  Index of selected COM Port in list
     * @return void
     */
    void showPortInfo(int idx);

    /**
     * \fn apply.
     * \brief Stores items local and closes window.
     * @return void
     */
    void apply();

    /**
     * \fn checkCustomBaudRatePolicy.
     * \brief Checks, if actual baudrate is valid.
     * If baudrate is valid, it can be applied. Else, the
     * input will be ignored.
     * @param  idx  Index of selected COM Port in list.
     * @return void
     */
    void checkCustomBaudRatePolicy(int idx);

    /**
     * \fn checkCustomDevicePathPolicy.
     * \brief Checks, if actual device is valid.
     * If device is valid, it can be applied. Else, the
     * input will be ignored.
     * @param  idx  Index of selected COM Port in list.
     * @return void
     */
    void checkCustomDevicePathPolicy(int idx);

private:
    /**
     * \fn fillPortsParameters.
     * \brief Initializes Textboxes.
     * Adds items like 9600, 19200 or 38400 for Baudrate.
     * @return void
     */
    void fillPortsParameters();

    /**
     * \fn fillPortsInfo.
     * \brief Initializes Textbox PortInfo.
     * Search for available COM ports and shos them in ListBox.
     * For each valid port will be shown information like
     * description, manufacturer, serial number or hardware IDs.
     * @return void
     */
    void fillPortsInfo();

    /**
     * \fn updateSettings.
     * \brief Stores actual Settings in local object.
     * @return void
     */
    void updateSettings();

private:
    /**
     * \var ui.
     * \brief Pointer to SettingsDialog type.
     * Address will be given in constructor.
     */
    Ui::SettingsDialog *ui;

    /**
     * \var currentSettings.
     * \brief actualSettings.
     * Contains actual settings.
     */
    Settings currentSettings;

    /**
     * \var intValidator.
     * \brief connects to a given String an integer value.
     * Adress will be given in constructor.
     */
    QIntValidator *intValidator;
};

#endif // SETTINGSDIALOG_H
