QT += quick
QT += network
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Sources/Connector/cconnector.cpp \
        Sources/DataLayer/cdatalayer.cpp \
        Sources/NetWork/cbinancenetwork.cpp \
        Sources/main.cpp


LIBS += -LC:\Qt\Tools\OpenSSL\Win_x64\lib -llibssl
LIBS += -LC:\Qt\Tools\OpenSSL\Win_x64\lib -llibcrypto

RESOURCES += Sources/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Sources/Connector/cconnector.h \
    Sources/DataLayer/cdatalayer.h \
    Sources/NetWork/cbinancenetwork.h

