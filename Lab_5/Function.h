///////////////////////////////////////////////////////////
// Function.h
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

class Function {
public:
    virtual ~Function() {}
    virtual const std::string& GetName() const = 0;
    virtual void Calculate() = 0;
protected:
    double x; // аргумент
};

#endif /* FUNCTION_H */
///////////////////////////////////////////////////////////