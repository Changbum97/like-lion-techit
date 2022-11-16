#include "IOperator.h"

class Sub : public IOperator {
public:
    virtual float op(float num1, float num2);
};