#include <iostream>

#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

std::string generateProgram() {
    CppClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc1", "void", 0 ),
        CppClassUnit::BaseAccessModifier::PUBLIC
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc2", "void", CppMethodUnit::STATIC ),
        CppClassUnit::BaseAccessModifier::PRIVATE
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc3", "void", CppMethodUnit::VIRTUAL |
                                                                 CppMethodUnit::CONST ),
        CppClassUnit::BaseAccessModifier::PUBLIC
        );
    auto method = std::make_shared< CppMethodUnit >( "testFunc4", "void",
                                                  CppMethodUnit::STATIC );
    method->add( std::make_shared< CppPrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, CppClassUnit::BaseAccessModifier::PROTECTED);

    myClass.add(std::make_shared<CppMethodUnit>("TEEST", "void"), CppClassUnit::CppAccessModifier::TEST);
    return myClass.compile();
}

int main() {
    std::cout << generateProgram() << std::endl;
    return 0;
}
