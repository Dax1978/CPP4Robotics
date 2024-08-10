QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/gamefield.cpp \
    src/main.cpp \
    src/snake.cpp

HEADERS += \
    include/gamefield.hpp \
    include/snake.hpp

# Строчка для указания файла ресурса (в моем случае это иконка приложения)
# CTRL + мышкой на resource.rc -> открою resource.rc и вписываю там соответствующее содержимое для иконки
win32:RC_FILE = resource.rc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#DISTFILES +=

RESOURCES += \
    img.qrc
