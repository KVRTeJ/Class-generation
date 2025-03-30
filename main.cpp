#include <iostream>

#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

std::string generateProgram() {
    CppClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc1", "void",  CppMethodUnit::base.CONST),
        CppClassUnit::BaseAccessModifier::PUBLIC
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc2", "void", 0 ),
        CppClassUnit::BaseAccessModifier::PRIVATE
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc3", "void", 0 |
                                                                0 ),
        CppClassUnit::BaseAccessModifier::PUBLIC
        );
    auto method = std::make_shared< CppMethodUnit >( "testFunc4", "void",
                                                  0 );
    method->add( std::make_shared< CppPrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, CppClassUnit::BaseAccessModifier::PROTECTED);

    return myClass.compile();
}

int main() {
    std::cout << generateProgram() << std::endl;
    return 0;
}
