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
public:
    explicit CsClassUnit(const std::string &name) : ClassUnit(name)
    { }

    void add(const std::shared_ptr<Unit> &unit, Flags flags = 0) override {

    }

    std::string compile(unsigned int level = 0) const override {
        return {};
    }

private:
    bool isAbstract = false;
};

#endif // CSCLASSUNIT_H
