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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionConfigure;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *LabelState;
    QPushButton *ButtonShow;
    QPushButton *ButtonAdd;
    QPushButton *ButtonDelete;
    QLabel *LabelBarcodeNum;
    QSpacerItem *verticalSpacer;
    QPushButton *ButtonBatchAdd;
    QTableWidget *tableWidget;
    QPushButton *ButtonBatchDelete;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(599, 335);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        actionConfigure = new QAction(MainWindow);
        actionConfigure->setObjectName(QStringLiteral("actionConfigure"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        LabelState = new QLabel(centralWidget);
        LabelState->setObjectName(QStringLiteral("LabelState"));
        LabelState->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LabelState, 1, 0, 1, 2);

        ButtonShow = new QPushButton(centralWidget);
        ButtonShow->setObjectName(QStringLiteral("ButtonShow"));

        gridLayout_2->addWidget(ButtonShow, 0, 2, 1, 1);

        ButtonAdd = new QPushButton(centralWidget);
        ButtonAdd->setObjectName(QStringLiteral("ButtonAdd"));

        gridLayout_2->addWidget(ButtonAdd, 0, 0, 1, 1);

        ButtonDelete = new QPushButton(centralWidget);
        ButtonDelete->setObjectName(QStringLiteral("ButtonDelete"));

        gridLayout_2->addWidget(ButtonDelete, 0, 1, 1, 1);

        LabelBarcodeNum = new QLabel(centralWidget);
        LabelBarcodeNum->setObjectName(QStringLiteral("LabelBarcodeNum"));
        QFont font;
        font.setFamily(QStringLiteral("C39HrP24DhTt"));
        font.setPointSize(30);
        font.setBold(false);
        font.setWeight(50);
        LabelBarcodeNum->setFont(font);
        LabelBarcodeNum->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(LabelBarcodeNum, 2, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 2);

        ButtonBatchAdd = new QPushButton(centralWidget);
        ButtonBatchAdd->setObjectName(QStringLiteral("ButtonBatchAdd"));
        ButtonBatchAdd->setMinimumSize(QSize(210, 0));

        gridLayout_2->addWidget(ButtonBatchAdd, 4, 0, 1, 2);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setRowCount(1);

        gridLayout_2->addWidget(tableWidget, 1, 2, 5, 1);

        ButtonBatchDelete = new QPushButton(centralWidget);
        ButtonBatchDelete->setObjectName(QStringLiteral("ButtonBatchDelete"));

        gridLayout_2->addWidget(ButtonBatchDelete, 5, 0, 1, 2);


        horizontalLayout->addLayout(gridLayout_2);

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
        LabelState->setText(QApplication::translate("MainWindow", "Bereit", 0));
        ButtonShow->setText(QApplication::translate("MainWindow", "Show Database", 0));
        ButtonAdd->setText(QApplication::translate("MainWindow", "Add to database", 0));
        ButtonDelete->setText(QApplication::translate("MainWindow", "Delete from Database", 0));
        LabelBarcodeNum->setText(QString());
        ButtonBatchAdd->setText(QApplication::translate("MainWindow", "BatchAdd", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Barcode", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Quantity", 0));
        ButtonBatchDelete->setText(QApplication::translate("MainWindow", "BatchDelete", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
