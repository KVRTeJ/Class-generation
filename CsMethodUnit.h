#ifndef CSMETHODUNIT_H
#define CSMETHODUNIT_H

#include "MethodUnit.h"

class CsMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        ABSTRACT = 1 << 1,
        VIRTUAL = 1 << 2,
        SEALED = 1 << 3,
        READONLY = 1 << 4,
        CONST = 1 << 5,
        EXTERN = 1 << 6
    };

public:
    CsMethodUnit(const std::string &name, const std::string &returnType, Flags flags = 0) :
        MethodUnit(name, returnType, flags)
    { }

    void add(const std::shared_ptr<Unit> &unit, Flags /* flags */ = 0) override {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const override {
        return {};
    }

    Flags getFlags() const override {return m_flags;}
};

#endif // CSMETHODUNIT_H
