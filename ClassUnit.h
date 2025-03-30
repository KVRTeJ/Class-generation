#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include <vector>

#include "Unit.h"

class ClassUnit : public Unit {
public:
    struct BaseAccessModifier {
        static const unsigned short PUBLIC = 0;
        static const unsigned short PROTECTED = 1;
        static const unsigned short PRIVATE = 2;
    };

public:
    explicit ClassUnit(const std::string &name) : m_name(name) {
         _initAccessModifiers();

        m_fields.resize(m_accessModifiers.size());
    }

    std::vector<std::string> getAccessModifiers() const {
        return m_accessModifiers;
    }

protected:
    virtual void _initAccessModifiers() {
        m_accessModifiers = {"public", "protected", "private"};
    }

    virtual void _addAccessModifiers(const std::vector<std::string> &other) {
        for(auto it = other.begin(); it != other.end(); ++it) {
            m_accessModifiers.push_back(*it);
        }
    }

protected:
    std::string m_name;

    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;

    std::vector<std::string> m_accessModifiers;
};


#endif // CLASSUNIT_H
