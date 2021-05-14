/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *flightIdEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *flightSeatsEdit;
    QPushButton *addFlightButton;
    QLabel *addFlightStatus;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QLineEdit *rflightIdEdit;
    QPushButton *removeFlightButton;
    QLabel *removeFlightStatus;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QLineEdit *queryFlightIdEdit;
    QCheckBox *cbOccupied;
    QCheckBox *cbSorted;
    QPushButton *queryFlightButton;
    QPlainTextEdit *queryFlightOutput;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *addCustomerFlightId;
    QSpinBox *addCustomerSeatNum;
    QLineEdit *addCustomerName;
    QLineEdit *addCustomerAddress;
    QLabel *label_7;
    QLineEdit *addCustomerPhoneNum;
    QPushButton *addCustomerSubmit;
    QLabel *addCustomerStatus;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QLineEdit *findCustomerName;
    QLabel *label_13;
    QLineEdit *findCustomerPhoneNum;
    QPushButton *findCustomerSubmit;
    QLabel *findCustomerStatus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 771, 541));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        verticalLayoutWidget = new QWidget(tab_1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 311, 129));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        flightIdEdit = new QLineEdit(verticalLayoutWidget);
        flightIdEdit->setObjectName(QString::fromUtf8("flightIdEdit"));
        flightIdEdit->setMaxLength(10);

        horizontalLayout->addWidget(flightIdEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        flightSeatsEdit = new QComboBox(verticalLayoutWidget);
        flightSeatsEdit->setObjectName(QString::fromUtf8("flightSeatsEdit"));

        horizontalLayout_3->addWidget(flightSeatsEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        addFlightButton = new QPushButton(verticalLayoutWidget);
        addFlightButton->setObjectName(QString::fromUtf8("addFlightButton"));

        verticalLayout->addWidget(addFlightButton);

        addFlightStatus = new QLabel(verticalLayoutWidget);
        addFlightStatus->setObjectName(QString::fromUtf8("addFlightStatus"));

        verticalLayout->addWidget(addFlightStatus);

        verticalLayoutWidget_2 = new QWidget(tab_1);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 180, 311, 129));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        rflightIdEdit = new QLineEdit(verticalLayoutWidget_2);
        rflightIdEdit->setObjectName(QString::fromUtf8("rflightIdEdit"));
        rflightIdEdit->setMaxLength(10);

        horizontalLayout_6->addWidget(rflightIdEdit);


        verticalLayout_3->addLayout(horizontalLayout_6);

        removeFlightButton = new QPushButton(verticalLayoutWidget_2);
        removeFlightButton->setObjectName(QString::fromUtf8("removeFlightButton"));

        verticalLayout_3->addWidget(removeFlightButton);

        removeFlightStatus = new QLabel(verticalLayoutWidget_2);
        removeFlightStatus->setObjectName(QString::fromUtf8("removeFlightStatus"));

        verticalLayout_3->addWidget(removeFlightStatus);

        verticalLayoutWidget_3 = new QWidget(tab_1);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(380, 10, 361, 301));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_11 = new QLabel(verticalLayoutWidget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        queryFlightIdEdit = new QLineEdit(verticalLayoutWidget_3);
        queryFlightIdEdit->setObjectName(QString::fromUtf8("queryFlightIdEdit"));
        queryFlightIdEdit->setMaxLength(10);

        horizontalLayout_7->addWidget(queryFlightIdEdit);


        verticalLayout_4->addLayout(horizontalLayout_7);

        cbOccupied = new QCheckBox(verticalLayoutWidget_3);
        cbOccupied->setObjectName(QString::fromUtf8("cbOccupied"));

        verticalLayout_4->addWidget(cbOccupied);

        cbSorted = new QCheckBox(verticalLayoutWidget_3);
        cbSorted->setObjectName(QString::fromUtf8("cbSorted"));

        verticalLayout_4->addWidget(cbSorted);

        queryFlightButton = new QPushButton(verticalLayoutWidget_3);
        queryFlightButton->setObjectName(QString::fromUtf8("queryFlightButton"));

        verticalLayout_4->addWidget(queryFlightButton);

        queryFlightOutput = new QPlainTextEdit(verticalLayoutWidget_3);
        queryFlightOutput->setObjectName(QString::fromUtf8("queryFlightOutput"));
        queryFlightOutput->setEnabled(true);
        queryFlightOutput->setReadOnly(true);

        verticalLayout_4->addWidget(queryFlightOutput);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget_4 = new QWidget(tab_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 0, 291, 236));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(verticalLayoutWidget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_6 = new QLabel(verticalLayoutWidget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(verticalLayoutWidget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        addCustomerFlightId = new QLineEdit(verticalLayoutWidget_4);
        addCustomerFlightId->setObjectName(QString::fromUtf8("addCustomerFlightId"));
        addCustomerFlightId->setMaxLength(10);

        gridLayout_2->addWidget(addCustomerFlightId, 0, 1, 1, 1);

        addCustomerSeatNum = new QSpinBox(verticalLayoutWidget_4);
        addCustomerSeatNum->setObjectName(QString::fromUtf8("addCustomerSeatNum"));
        addCustomerSeatNum->setMaximum(49);

        gridLayout_2->addWidget(addCustomerSeatNum, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        addCustomerName = new QLineEdit(verticalLayoutWidget_4);
        addCustomerName->setObjectName(QString::fromUtf8("addCustomerName"));
        addCustomerName->setMaxLength(32);

        verticalLayout_2->addWidget(addCustomerName);

        addCustomerAddress = new QLineEdit(verticalLayoutWidget_4);
        addCustomerAddress->setObjectName(QString::fromUtf8("addCustomerAddress"));
        addCustomerAddress->setMaxLength(32);

        verticalLayout_2->addWidget(addCustomerAddress);

        label_7 = new QLabel(verticalLayoutWidget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        addCustomerPhoneNum = new QLineEdit(verticalLayoutWidget_4);
        addCustomerPhoneNum->setObjectName(QString::fromUtf8("addCustomerPhoneNum"));

        verticalLayout_2->addWidget(addCustomerPhoneNum);

        addCustomerSubmit = new QPushButton(verticalLayoutWidget_4);
        addCustomerSubmit->setObjectName(QString::fromUtf8("addCustomerSubmit"));

        verticalLayout_2->addWidget(addCustomerSubmit);

        addCustomerStatus = new QLabel(verticalLayoutWidget_4);
        addCustomerStatus->setObjectName(QString::fromUtf8("addCustomerStatus"));

        verticalLayout_2->addWidget(addCustomerStatus);

        verticalLayoutWidget_5 = new QWidget(tab_2);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(420, 10, 311, 141));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(verticalLayoutWidget_5);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_5->addWidget(label_12);

        findCustomerName = new QLineEdit(verticalLayoutWidget_5);
        findCustomerName->setObjectName(QString::fromUtf8("findCustomerName"));
        findCustomerName->setMaxLength(32);

        verticalLayout_5->addWidget(findCustomerName);

        label_13 = new QLabel(verticalLayoutWidget_5);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);

        findCustomerPhoneNum = new QLineEdit(verticalLayoutWidget_5);
        findCustomerPhoneNum->setObjectName(QString::fromUtf8("findCustomerPhoneNum"));

        verticalLayout_5->addWidget(findCustomerPhoneNum);

        findCustomerSubmit = new QPushButton(verticalLayoutWidget_5);
        findCustomerSubmit->setObjectName(QString::fromUtf8("findCustomerSubmit"));

        verticalLayout_5->addWidget(findCustomerSubmit);

        findCustomerStatus = new QLabel(verticalLayoutWidget_5);
        findCustomerStatus->setObjectName(QString::fromUtf8("findCustomerStatus"));

        verticalLayout_5->addWidget(findCustomerStatus);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Add Flights:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Flight ID:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "# Seats:", nullptr));
        addFlightButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        addFlightStatus->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Remove Flights:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Flight ID:", nullptr));
        removeFlightButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        removeFlightStatus->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Query Flight:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Flight ID:", nullptr));
        cbOccupied->setText(QCoreApplication::translate("MainWindow", "Show Occupied Seats Only", nullptr));
        cbSorted->setText(QCoreApplication::translate("MainWindow", "Sort by Occupant Name", nullptr));
        queryFlightButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        queryFlightOutput->setPlainText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QCoreApplication::translate("MainWindow", "Flights", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Add Customer Seat Reservation", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Seat #:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Flight ID:", nullptr));
        addCustomerName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Customer Name", nullptr));
        addCustomerAddress->setPlaceholderText(QCoreApplication::translate("MainWindow", "Customer Address", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Customer Phone Number:", nullptr));
        addCustomerPhoneNum->setInputMask(QCoreApplication::translate("MainWindow", "(999) 999-9999", nullptr));
        addCustomerPhoneNum->setPlaceholderText(QString());
        addCustomerSubmit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        addCustomerStatus->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Find Customer Seat Reservation", nullptr));
        findCustomerName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Customer Name", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Customer Phone Number:", nullptr));
        findCustomerPhoneNum->setInputMask(QCoreApplication::translate("MainWindow", "(999) 999-9999", nullptr));
        findCustomerPhoneNum->setPlaceholderText(QString());
        findCustomerSubmit->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        findCustomerStatus->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Customers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
