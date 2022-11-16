// 한 번만 호출
#pragma once

class IOperator {
public:
    virtual float op(float num1, float num2) = 0;
};