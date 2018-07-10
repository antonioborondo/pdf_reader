#-------------------------------------------------
#
# Project created by QtCreator 2018-07-09T12:22:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pdf_reader
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        pdf_reader.cpp \
    document.cpp \
    context.cpp

HEADERS += \
        pdf_reader.h \
    document.h \
    context.h

FORMS += \
        pdf_reader.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/mupdf/build/release/ -lmupdf -lmupdfthird
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/mupdf/build/debug/ -lmupdf -lmupdfthird
else:unix: LIBS += -L$$PWD/lib/mupdf/build/ -lmupdf -lmupdfthird

INCLUDEPATH += $$PWD/lib/mupdf/include
DEPENDPATH += $$PWD/lib/mupdf/include
