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

void testCsMethodUnit() {
    // 1. Без флагов
    CsMethodUnit test1("test1", "void");
    assert(test1.compile() == "void test1() {\n}\n");

    // 2. ABSTRACT
    CsMethodUnit test2("test2", "void", CsMethodUnit::ABSTRACT);
    assert(test2.compile() == "abstract void test2() {\n}\n");

    // 3. SEALED
    CsMethodUnit test3("test3", "void", CsMethodUnit::SEALED);
    assert(test3.compile() == "sealed void test3() {\n}\n");

    // 4. STATIC
    CsMethodUnit test4("test4", "void", CsMethodUnit::STATIC);
    assert(test4.compile() == "static void test4() {\n}\n");

    // 5. VIRTUAL
    CsMethodUnit test5("test5", "void", CsMethodUnit::VIRTUAL);
    assert(test5.compile() == "virtual void test5() {\n}\n");

    // 6. CONST
    CsMethodUnit test6("test6", "void", CsMethodUnit::CONST);
    assert(test6.compile() == "const void test6() {\n}\n");

    // 7. READONLY
    CsMethodUnit test7("test7", "void", CsMethodUnit::READONLY);
    assert(test7.compile() == "readonly void test7() {\n}\n");

    // 8.
    CsMethodUnit test8("test8", "void", CsMethodUnit::ABSTRACT | CsMethodUnit::CONST);
    assert(test8.compile() == "abstract const void test8() {\n}\n");

    CsMethodUnit test9("test9", "void", CsMethodUnit::STATIC | CsMethodUnit::VIRTUAL);
    assert(test9.compile() != "virtual static void test9() {\n}\n");

    CsMethodUnit test10("test10", "void", CsMethodUnit::SEALED | CsMethodUnit::READONLY);
    assert(test10.compile() == "sealed readonly void test10() {\n}\n");

    std::cout << "All tests passed!" << std::endl;
}

int main() {

    testCsMethodUnit();

    return 0;
}
