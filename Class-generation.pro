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
    MethodUnit.h \
    PrintOperatorUnit.h \
    Unit.h
