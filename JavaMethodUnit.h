#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H

#include "MethodUnit.h"

class JavaMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        FINAL = 1 << 1,
        ABSTRACT = 1 << 2,
    };

public:
    JavaMethodUnit(const std::string &name, const std::string &returnType, Flags flags = 0) :
        MethodUnit(name, returnType, flags)
    { }

    void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0) override {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level);

        if(m_flags & STATIC)
            result += "static ";
        if(m_flags & FINAL)
            result += "final ";
        else if(m_flags & ABSTRACT)
            result += "abstract ";

        result += m_returnType + ' ';
        result += m_name + "() ";


        result += "{\n";
        for(auto it = m_body.begin(); it != m_body.end(); ++it) {
            result += (*it)->compile(level + 1);
        }

        result += generateShift(level) + "}\n";

        return result;
    }

    Flags getFlags() const override {return m_flags;}
};


#endif // JAVAMETHODUNIT_H
