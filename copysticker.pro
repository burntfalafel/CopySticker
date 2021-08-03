TEMPLATE = app
TARGET = CopySticker

QT = core gui

LIBS += -L/usr/include/jsoncpp -ljsoncpp

INCLUDEPATH += $$PWD/include

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    src/main.cpp \
    src/preview_file_dialog.cpp \
    src/window.cpp

HEADERS += \
    include/preview_file_dialog.h \
    include/window.h
