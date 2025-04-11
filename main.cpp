#include <iostream>

#include <assert.h>

#include "CppClassUnit.h"
#include "CppMethodUnit.h"
#include "CppPrintOperatorUnit.h"

#include "JavaPrintMethodUnit.h"
#include "JavaMethodUnit.h"
#include "JavaClassUnit.h"

#include "CsPrintOperatorUnit.h"
#include "CsMethodUnit.h"
#include "CsClassUnit.h"

int main() {

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
