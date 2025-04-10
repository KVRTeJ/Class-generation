#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <vector>

#include "Unit.h"

class ClassUnit : public Unit {
public:
    enum BaseAccessModifier : Flags {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

    static const std::vector<std::string> BASE_ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string &name) : m_name(name) {
        m_fields.resize(BASE_ACCESS_MODIFIERS.size());
    }

protected:
    std::string m_name;

    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

const std::vector<std::string> ClassUnit::BASE_ACCESS_MODIFIERS = {"public", "protected", "private"};

#endif // CLASSUNIT_H
