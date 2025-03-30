#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H

#include <vector>

#include "ClassUnit.h"

class CppClassUnit : public ClassUnit {
public:
    explicit CppClassUnit(const std::string &name) : ClassUnit(name)
    { }

    void add(const std::shared_ptr<Unit> &unit, Flags flags) override {
        int accessModifier = BaseAccessModifier::PRIVATE;

        if(flags < m_accessModifiers.size()) {
            accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }

    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + "class " + m_name + " {\n";
        for(size_t i = 0; i < m_accessModifiers.size(); ++i) {
            if(m_fields[i].empty()) {
                continue;
            }

            result += m_accessModifiers[i] + ":\n";
            for(const auto &f : m_fields[i]) {
                result += f->compile(level + 1);
            }

            result += "\n";
        }
        result += generateShift(level) + "};\n";
        return result;
    }
};

#endif // CPPCLASSUNIT_H
