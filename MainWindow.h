#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "RBTree.h"
#include "Flight.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); // 1 of 3
    // since this is an object intended to interface with Qt, these are unneeded:
    MainWindow& operator=(const MainWindow &rhs) = delete; // 2 of 3
    MainWindow(const MainWindow &mw) = delete; // 3 of 3

private:
    Ui::MainWindow *ui; // a special Qt class

    RBTree flights, customers; // database objects
    bool showOccupiedOnly = false, sortByName = false; // flags for how flight information is printed

    // helper functions for saving and loading the database objects:
    void loadDataHelper(Record *r);
    void loadDataBases();
    void saveDataBases();

private slots: // functions that Qt calls whenever a GUI event happens
    void on_addFlightButton_released();
    void on_removeFlightButton_released();
    void on_queryFlightButton_released();
    void on_cbOccupied_stateChanged(int arg1);
    void on_cbSorted_stateChanged(int arg1);

    void on_addCustomerSubmit_released();
    void on_findCustomerSubmit_released();
};
#endif // MAINWINDOW_H
