#include <iostream>

#include "Factory.h"

std::string generateProgram(iFactory *factory) {
    std::shared_ptr<ClassUnit> myClass = factory->makeClass("MyClass");
    myClass->add(
        factory->makeMethod( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass->add(
        factory->makeMethod("testFunc2", "void", 1),
        ClassUnit::PRIVATE
        );
    myClass->add(
        factory->makeMethod("testFunc3", "void", 1 | (1 << 2)),
        ClassUnit::PUBLIC
        );
    auto method = factory->makeMethod("testFunc4", "void", 1);
    // method->add(factory->makePrintOperator("Hello, world!\n"));
    myClass->add(method, (1 << 3));
    return myClass->compile();
}

int main() {

}
