QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pdf_reader
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    src/pdf_reader.h

SOURCES += \
    src/main.cpp \
    src/pdf_reader.cpp

FORMS += \
    src/pdf_reader.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mupdf_wrapper/release/ -lmupdf_wrapper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mupdf_wrapper/debug/ -lmupdf_wrapper
else:unix: LIBS += -L$$OUT_PWD/../mupdf_wrapper/ -lmupdf_wrapper

INCLUDEPATH += $$PWD/../mupdf_wrapper/include
DEPENDPATH += $$PWD/../mupdf_wrapper/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../lib/mupdf/build/release/ -lmupdf -lmupdfthird
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../lib/mupdf/build/debug/ -lmupdf -lmupdfthird
else:unix: LIBS += -L$$PWD/../../lib/mupdf/build/ -lmupdf -lmupdfthird

INCLUDEPATH += $$PWD/../../lib/mupdf/include
DEPENDPATH += $$PWD/../../lib/mupdf/include
