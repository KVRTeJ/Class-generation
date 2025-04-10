#ifndef CSPRINTOPERATORUNIT_H
#define CSPRINTOPERATORUNIT_H

#include "PrintOperatorUnit.h"

class CsPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit CsPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text)
    { }

    std::string compile(unsigned int level = 0) const override {
        return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
    }
};

#endif // CSPRINTOPERATORUNIT_H
