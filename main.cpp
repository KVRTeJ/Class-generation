#include <iostream>

#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

std::string generateProgram() {
    CppClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc1", "void", 0 ),
        CppClassUnit::PUBLIC
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc2", "void", CppMethodUnit::STATIC ),
        CppClassUnit::PRIVATE
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc3", "void", CppMethodUnit::VIRTUAL |
                                                                 CppMethodUnit::CONST ),
        CppClassUnit::PUBLIC
        );
    auto method = std::make_shared< CppMethodUnit >( "testFunc4", "void",
                                                  CppMethodUnit::STATIC );
    method->add( std::make_shared< CppPrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, CppClassUnit::PROTECTED );
    return myClass.compile();
}

int main() {
    std::cout << generateProgram() << std::endl;
    return 0;
}
