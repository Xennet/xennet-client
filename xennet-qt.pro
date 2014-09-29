QT += core gui network widgets

CONFIG += c++11 debug

HEADERS += \
    xennet.h \
    model.h \
    channel_t.h \
    wallet.h \
    mainwindow.h

SOURCES += \
    xennet.cpp \
    channel_t.cpp \
    model.cpp \
    wallet.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui
