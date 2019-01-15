# Base Settings
include($$TOP_SRCDIR/common.pri)

# Project Settings
QT -= gui
QT += websockets
CONFIG += c++11 console

# Target Settings

TARGET = Updater
VERSION = 0.1.0
APP_DOMAIN=Nulstar
APP_ROLE=Role_UpdateManager
APP_ROLE_VERSION=0.1
APP_NAME=$$TARGET
APP_VERSION=$$VERSION
APP_VERSION_NAME=Baby Apple I

DESTDIR=$$MODULES_OUTDIR/$$APP_DOMAIN/$$TARGET/$$VERSION

# Install Settings

OTHER_FILES += Module.ncf
COPYFILE1 = \"$$PWD/Module.ncf\" \"$$DESTDIR\"
win32: COPYFILE1 ~= s,/,\\,g
QMAKE_POST_LINK += $$QMAKE_COPY $$COPYFILE1

# Source Files

QMAKE_SUBSTITUTES += AppVersion.h.in

HEADERS += NUpdateController.h

SOURCES += NUpdateController.cpp \
           main.cpp

# Dependencies

INCLUDEPATH += $$LIBRARIES_PATH/Nulstar/NNetwork \
            $$LIBRARIES_PATH/Nulstar/NCore
LIBS += -lNNetwork -lNCore
