#include "../include/MonthlyAnalysis.h"

bool MonthlyAnalysis::isTargetData(string date) {
    bool res = false;
    res = date.substr(0, 6) == this->date;

    return res;
}