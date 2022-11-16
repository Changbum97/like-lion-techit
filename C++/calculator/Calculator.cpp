#include "Calculator.h"
#include "Add.h"
#include "Sub.h"
#include "Mul.h"
#include "Divide.h"
#include <iostream>

using namespace std;

void Calculator::input() {
    cin >> num1 >> op >> num2;

    // 연산자에 따라 알맞는 연산 동적 할당
    if(op == '+')
        iop = (IOperator *)new Add();
    else if(op == '-')
        iop = (IOperator *)new Sub();
    else if(op == '*')
        iop = (IOperator *)new Mul();
    else if(op == '/')
        iop = (IOperator *)new Divide();
}

void Calculator::calculate() {
    res = iop -> op(num1, num2);
    delete iop;
}

void Calculator::output() {
    cout << res << endl;
}
