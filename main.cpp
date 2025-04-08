#include <iostream>

#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

#include "JavaPrintMethodUnit.h"
#include "JavaMethodUnit.h"
#include "JavaClassUnit.h"

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
    JavaMethodUnit boo("JAVA_IS_HERE", "void", (JavaMethodUnit::FINAL | JavaMethodUnit::STATIC));
    boo.add(std::make_shared<JavaPrintOperatorUnit>(R"(Hello, world!\n)"));
    boo.add(std::make_shared<JavaPrintOperatorUnit>(R"(Bye, world!\n)"));

    JavaMethodUnit boo1("JAVA_IS_HERE2", "string", (JavaMethodUnit::ABSTRACT | JavaMethodUnit::STATIC));
    JavaMethodUnit boo2("JAVA_IS_HERE3", "int", (JavaMethodUnit::STATIC));

    JavaClassUnit foo("JavaClass");
    foo.add(std::make_shared<JavaMethodUnit>(boo), 0);
    foo.add(std::make_shared<JavaMethodUnit>(boo1), 2);
    foo.add(std::make_shared<JavaMethodUnit>(boo2), 0);
    std::cout << foo.compile();
    return 0;
}
