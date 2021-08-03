TEMPLATE = app
TARGET = helloworldqmake

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    preview_file_dialog.cpp \
    window.cpp

HEADERS += \
    preview_file_dialog.h \
    window.h
