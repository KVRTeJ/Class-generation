#ifndef JAVAPRINTMETHODUNIT_H
#define JAVAPRINTMETHODUNIT_H

#include "PrintOperatorUnit.h"

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit JavaPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text)
    { }

    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "System.out.println(\"" + m_text + "\");\n";
    }
};


#endif // JAVAPRINTMETHODUNIT_H
