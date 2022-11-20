#include "../include/YearlyAnalysis.h"

bool YearlyAnalysis::isTargetData(string date) {
    bool res = false;
    res = date.substr(0, 4) == this->date;

    return res;
}