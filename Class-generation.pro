TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ClassUnit.h \
    CppClassUnit.h \
    CppMethodUnit.h \
    CppPrintOperatorUnit.h \
    CsClassUnit.h \
    CsMethodUnit.h \
    CsPrintOperatorUnit.h \
    JavaClassUnit.h \
    JavaMethodUnit.h \
    JavaPrintMethodUnit.h \
    MethodUnit.h \
    PrintOperatorUnit.h \
    Unit.h
