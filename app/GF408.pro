QT       += core gui
QT       += core gui androidextras
QT       +=sql
QT += androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    answerdlg.cpp \
    dialog.cpp \
    logindialog.cpp \
    main.cpp \
    questiondialog.cpp \
    questionyeardialog.cpp \
    userdatadlg.cpp \
    widget.cpp

HEADERS += \
    answerdlg.h \
    dialog.h \
    logindialog.h \
    questiondialog.h \
    questionyeardialog.h \
    userdatadlg.h \
    widget.h

FORMS += \
    answerdlg.ui \
    dialog.ui \
    logindialog.ui \
    questiondialog.ui \
    questionyeardialog.ui \
    userdatadlg.ui \
    widget.ui
#设置数据库的路径和编译后数据库的路径,将使用的数据库放入这个路径
android{
        data.files += database/data.db
        data.files += database/username.txt
        data.path = /assets/database #在安卓手机查找数据库的路径
        INSTALLS += data
    }


#设置安卓名字图标的文件夹
ANDROID_PACKAGE_SOURCE_DIR=$$PWD/androidset


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc

DISTFILES += \
    androidset/AndroidManifest.xml \
    androidset/S6M4_1VG{M510V98FT5AG5P.png \
    androidset/build.gradle \
    androidset/gggg.png \
    androidset/gradle/wrapper/gradle-wrapper.jar \
    androidset/gradle/wrapper/gradle-wrapper.properties \
    androidset/gradlew \
    androidset/gradlew.bat \
    androidset/libs/mysql-connector-java-5.1.49.jar \
    androidset/libs/mysql-connector-java-6.0.6.jar \
    androidset/res/values/libs.xml \
    androidset/src/com/javaForcpp/UserLogin.java \
    androidset/src/com/javaForcpp/jdbcForCplusCplus.java \
    database/username.txt
