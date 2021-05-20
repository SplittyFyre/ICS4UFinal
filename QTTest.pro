QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Customer.cpp \
    EasySaveLoad.cpp \
    Flight.cpp \
    MainWindow.cpp \
    RBNode.cpp \
    RBTree.cpp \
    main.cpp

HEADERS += \
    Customer.h \
    EasySaveLoad.h \
    Flight.h \
    MainWindow.h \
    RBNode.h \
    RBTree.h \
    Record.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
