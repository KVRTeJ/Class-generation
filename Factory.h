#ifndef FACTORY_H
#define FACTORY_H

#include <memory>

#include "CppPrintOperatorUnit.h"
#include "CppMethodUnit.h"
#include "CppClassUnit.h"

#include "JavaPrintMethodUnit.h"
#include "JavaMethodUnit.h"
#include "JavaClassUnit.h"

#include "CsPrintOperatorUnit.h"
#include "CsMethodUnit.h"
#include "CsClassUnit.h"

class iFactory {
public:
    virtual std::shared_ptr<ClassUnit> makeClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> makeMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> makePrintOperator(const std::string& text) = 0;
};

class CppFactory : public iFactory {
public:
    std::shared_ptr<ClassUnit> makeClass(const std::string& name) override {
        return std::make_shared<CppClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> makeMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<CppMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> makePrintOperator(const std::string& text) override {
        return std::make_shared<CppPrintOperatorUnit>(text);
    }
};

class JavaFactory : public iFactory {
public:
    std::shared_ptr<ClassUnit> makeClass(const std::string& name) override {
        return std::make_shared<JavaClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> makeMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<JavaMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> makePrintOperator(const std::string& text) override {
        return std::make_shared<JavaPrintOperatorUnit>(text);
    }
};

class CsFactory : public iFactory {
public:
    std::shared_ptr<ClassUnit> makeClass(const std::string& name) override {
        return std::make_shared<CsClassUnit>(name);
    }
    std::shared_ptr<MethodUnit> makeMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override {
        return std::make_shared<CsMethodUnit>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> makePrintOperator(const std::string& text) override {
        return std::make_shared<CsPrintOperatorUnit>(text);
    }
};


#endif // FACTORY_H
