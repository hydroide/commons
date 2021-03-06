#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T08:42:14
#
#-------------------------------------------------

#QT       -= gui

TARGET = commons
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(interfaces/interfaces.pri)
include(database/database.pri)
include(settings/settings.pri)
include(helpers/helpers.pri)
include(modules/modules.pri)
include(models/models.pri)

SOURCES +=

HEADERS += \
    hcglobaldefs.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

BOOST_PATH = ../dependencies/boost

INCLUDEPATH += $$BOOST_PATH
LIBS += -L"$$BOOST_PATH/stage/lib"
