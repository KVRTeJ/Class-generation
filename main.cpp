#include <iostream>

#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

#include "JavaPrintMethodUnit.h"

std::string generateProgram() {
    CppClassUnit myClass( "MyClass" );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc1", "void",  0),
        CppClassUnit::BaseAccessModifier::PUBLIC
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc2", "void", CppMethodUnit::STATIC ),
        CppClassUnit::BaseAccessModifier::PRIVATE
        );
    myClass.add(
        std::make_shared< CppMethodUnit >( "testFunc3", "void", CppMethodUnit::CONST |
                                                                CppMethodUnit::VIRTUAL ),
        CppClassUnit::BaseAccessModifier::PUBLIC
        );
    auto method = std::make_shared< CppMethodUnit >( "testFunc4", "void",
                                                  0 );
    method->add( std::make_shared< CppPrintOperatorUnit >( R"(Hello, world!\n)" ) );
    myClass.add( method, CppClassUnit::BaseAccessModifier::PROTECTED);

    return myClass.compile();
}

int main() {
    //std::cout << generateProgram() << std::endl;
    JavaPrintOperatorUnit boo("JAVA IS HERE");
    std::cout << boo.compile() << std::endl;
    return 0;
}
