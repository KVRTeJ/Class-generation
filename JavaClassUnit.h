#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "ClassUnit.h"
#include "JavaMethodUnit.h"

class JavaClassUnit : public ClassUnit {
public:
    explicit JavaClassUnit(const std::string &name) : ClassUnit(name)
    { }

    void add(const std::shared_ptr<Unit> &unit, Flags flags = 0) override {
        if(!isAbstract & static_cast<bool>(unit->getFlags() & JavaMethodUnit::ABSTRACT)) {
            isAbstract = true;
        }

        int accessModifier = BaseAccessModifier::PUBLIC;

        if(flags < BASE_ACCESS_MODIFIERS.size()) {
            accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }

    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + (isAbstract ? "abstract " : "")
        + "class " + m_name + " {\n";

        for(size_t i = 0; i < BASE_ACCESS_MODIFIERS.size(); ++i) {
            if(m_fields[i].empty()) {
                continue;
            }

            for(const auto &f : m_fields[i]) {
                result += BASE_ACCESS_MODIFIERS[i] + ' ';
                result += f->compile(level);
            }

            result += "\n";
        }

        result += generateShift(level) + "};\n";

        return result;
    }

private:
    bool isAbstract = false;
};

#endif // JAVACLASSUNIT_H
