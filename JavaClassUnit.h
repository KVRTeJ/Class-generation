#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "ClassUnit.h"

class JavaClassUnit : public ClassUnit {
public:
    explicit JavaClassUnit(const std::string &name) : ClassUnit(name)
    { }

    void add(const std::shared_ptr<Unit> &unit, Flags flags) override {
        throw std::runtime_error("Not supported");
    }

    std::string compile(unsigned int level = 0) const override {
        throw std::runtime_error("Not supported");
    }
};

#endif // JAVACLASSUNIT_H
