QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cmp.cpp \
    getter_setter_auto.cpp \
    helper.cpp \
    main.cpp \
    dslk_don.cpp \
    dslk_kep.cpp \
    dslk_vong.cpp \
    mainwindow.cpp \
    read_write.cpp \
    sinhvien.cpp


HEADERS += \
    DanhSach.h \
    helper.h \
    dslk_don.h \
    dslk_kep.h \
    dslk_vong.h \
    mainwindow.h \
    read_write.h \
    sinhvien.h

FORMS += \
    form.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
