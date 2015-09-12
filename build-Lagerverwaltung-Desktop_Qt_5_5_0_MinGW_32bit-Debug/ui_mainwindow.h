/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ButtonAdd;
    QPushButton *ButtonDelete;
    QLabel *LabelBarcodeNum;
    QLabel *LabelState;
    QSpacerItem *verticalSpacer;
    QPushButton *ButtonBatchAdd;
    QPushButton *ButtonBatchDelete;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ButtonShow;
    QTableWidget *tableWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(574, 302);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget_2 = new QWidget(centralWidget);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 521, 231));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ButtonAdd = new QPushButton(horizontalLayoutWidget_2);
        ButtonAdd->setObjectName(QStringLiteral("ButtonAdd"));

        horizontalLayout->addWidget(ButtonAdd);

        ButtonDelete = new QPushButton(horizontalLayoutWidget_2);
        ButtonDelete->setObjectName(QStringLiteral("ButtonDelete"));

        horizontalLayout->addWidget(ButtonDelete);


        verticalLayout->addLayout(horizontalLayout);

        LabelBarcodeNum = new QLabel(horizontalLayoutWidget_2);
        LabelBarcodeNum->setObjectName(QStringLiteral("LabelBarcodeNum"));
        QFont font;
        font.setPointSize(10);
        LabelBarcodeNum->setFont(font);
        LabelBarcodeNum->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LabelBarcodeNum);

        LabelState = new QLabel(horizontalLayoutWidget_2);
        LabelState->setObjectName(QStringLiteral("LabelState"));
        LabelState->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(LabelState);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        ButtonBatchAdd = new QPushButton(horizontalLayoutWidget_2);
        ButtonBatchAdd->setObjectName(QStringLiteral("ButtonBatchAdd"));

        verticalLayout->addWidget(ButtonBatchAdd);

        ButtonBatchDelete = new QPushButton(horizontalLayoutWidget_2);
        ButtonBatchDelete->setObjectName(QStringLiteral("ButtonBatchDelete"));

        verticalLayout->addWidget(ButtonBatchDelete);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        ButtonShow = new QPushButton(horizontalLayoutWidget_2);
        ButtonShow->setObjectName(QStringLiteral("ButtonShow"));

        verticalLayout_2->addWidget(ButtonShow);

        tableWidget = new QTableWidget(horizontalLayoutWidget_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setRowCount(1);

        verticalLayout_2->addWidget(tableWidget);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionConfigure);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionConnect->setText(QApplication::translate("MainWindow", "C&onnect", 0));
#ifndef QT_NO_TOOLTIP
        actionConnect->setToolTip(QApplication::translate("MainWindow", "Connect to Serial Port", 0));
#endif // QT_NO_TOOLTIP
        actionConnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionDisconnect->setText(QApplication::translate("MainWindow", "&Disconnect", 0));
#ifndef QT_NO_TOOLTIP
        actionDisconnect->setToolTip(QApplication::translate("MainWindow", "Disconnect from Serial Port", 0));
#endif // QT_NO_TOOLTIP
        actionDisconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0));
        actionConfigure->setText(QApplication::translate("MainWindow", "&Configure", 0));
#ifndef QT_NO_TOOLTIP
        actionConfigure->setToolTip(QApplication::translate("MainWindow", "Configure", 0));
#endif // QT_NO_TOOLTIP
        actionConfigure->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        ButtonAdd->setText(QApplication::translate("MainWindow", "Add to database", 0));
        ButtonDelete->setText(QApplication::translate("MainWindow", "Delete from Database", 0));
        LabelBarcodeNum->setText(QString());
        LabelState->setText(QApplication::translate("MainWindow", "Bereit", 0));
        ButtonBatchAdd->setText(QApplication::translate("MainWindow", "BatchAdd", 0));
        ButtonBatchDelete->setText(QApplication::translate("MainWindow", "BatchDelete", 0));
        ButtonShow->setText(QApplication::translate("MainWindow", "Show Database", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Barcode", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Quantity", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
