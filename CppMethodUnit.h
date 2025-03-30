#ifndef CPPMETHODUNIT_H
#define CPPMETHODUNIT_H

#include "MethodUnit.h"

class CppMethodUnit : public MethodUnit {
public:
    CppMethodUnit(const std::string &name, const std::string &returnType, Flags flags = 0) :
    MethodUnit(name, returnType, flags)
    { }

    void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0) override {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level);
        if(m_flags & BaseModifier::STATIC)
            result += "static ";
        else if(m_flags & BaseModifier::VIRTUAL)
            result += "virtual ";


        result += m_returnType + " ";
        result += m_name + "()";

        if(m_flags & BaseModifier::CONST)
            result += " const";

        result += " {\n";
        for(const auto& b : m_body)
            result += b->compile(level + 1);

        result += generateShift(level) + "}\n";

        return result;
    }
};

#endif // CPPMETHODUNIT_H
