#ifndef CSCLASSUNIT_H
#define CSCLASSUNIT_H

#include "ClassUnit.h"
#include "CsMethodUnit.h"

class CsClassUnit : public ClassUnit {
public:
    enum CsAccesModifier : Flags {
        PUBLIC = BaseAccessModifier::PUBLIC,
        PROTECTED = BaseAccessModifier::PROTECTED,
        PRIVATE = BaseAccessModifier::PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL
    };

    static const std::vector<std::string> CS_ACCESS_MODIFIERS;
public:
    explicit CsClassUnit(const std::string &name) : ClassUnit(name) {
        m_fields.resize(BASE_ACCESS_MODIFIERS.size() + CS_ACCESS_MODIFIERS.size());
    }

    void add(const std::shared_ptr<Unit> &unit, Flags flags = 0) override {
        if(!isAbstract & static_cast<bool>(unit->getFlags() & CsMethodUnit::ABSTRACT)) {
            isAbstract = true;
        }

        int accessModifier = BaseAccessModifier::PUBLIC;

        if(flags < (BASE_ACCESS_MODIFIERS.size() + CS_ACCESS_MODIFIERS.size())) {
            accessModifier = flags;
        }

        m_fields[accessModifier].push_back(unit);
    }

    std::string compile(unsigned int level = 0) const override {
        std::string result = generateShift(level) + (isAbstract ? "abstract " : "")
        + "class " + m_name + " {\n";

        int accessModifiersSize = BASE_ACCESS_MODIFIERS.size() + CS_ACCESS_MODIFIERS.size();
        for(size_t i = 0; i < accessModifiersSize; ++i) {
            if(m_fields[i].empty()) {
                continue;
            }

            for(const auto &f : m_fields[i]) {
                result += ((i > BASE_ACCESS_MODIFIERS.size() - 1) ?
                               CS_ACCESS_MODIFIERS[i - BASE_ACCESS_MODIFIERS.size()]:
                               BASE_ACCESS_MODIFIERS[i]) + ' ';
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

const std::vector<std::string> CsClassUnit::CS_ACCESS_MODIFIERS = {"private protected", "file", "internal", "protected internal"};

#endif // CSCLASSUNIT_H
