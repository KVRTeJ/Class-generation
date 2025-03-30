#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <vector>

#include "Unit.h"

class ClassUnit : public Unit {
public:
    enum AccessModifier { //TODO: to struct ????
        PUBLIC,
        PROTECTED,
        PRIVATE
    };

public:
    explicit ClassUnit(const std::string &name) : m_name(name) {
        if(!m_accessModifiers.size()) {
            _initAccesModifiers();
        }

        m_fields.resize(m_accessModifiers.size());
    }

protected:
    virtual void _initAccesModifiers() {
        m_accessModifiers = {"public", "protected", "private"};
    }

protected:
    std::string m_name;

    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

    std::vector<std::string> m_accessModifiers;
};

#endif // CLASSUNIT_H
