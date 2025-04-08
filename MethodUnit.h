#ifndef METHODUNIT_H
#define METHODUNIT_H

#include <vector>

#include "Unit.h"

class MethodUnit : public Unit {
public:
    MethodUnit(const std::string &name, const std::string &returnType, Flags flags) :
        m_name(name), m_returnType(returnType), m_flags(flags)
    { }

    Flags getFlags() const override {return m_flags;}

protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif // METHODUNIT_H
