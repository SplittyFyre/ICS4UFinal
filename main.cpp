#include "MainWindow.h"

#include <QApplication>

// main function starts Qt
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
