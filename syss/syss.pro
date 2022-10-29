QT       += core gui
QT       += core gui multimediawidgets multimedia
QT       +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    registerdialog.cpp \
    widget.cpp

HEADERS += \
    registerdialog.h \
    widget.h

FORMS += \
    registerdialog.ui \
    widget.ui

RC_ICONS=icon6.ico

INCLUDEPATH +=C:/opencv/build/include\
              C:/opencv/build/include/opencv2
LIBS+=C:/opencv/mingwBuild/lib/libopencv_*.a
LIBS+=-LC:\opencv\mingwBuild\install\x64\mingw\bin

INCLUDEPATH +=C:/dlib-19.24/dlibProject/include
LIBS +=C:/dlib-19.24/dlibProject/lib/libdlib.a

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    data.db \
    haarcascade_frontalface_alt.xml
