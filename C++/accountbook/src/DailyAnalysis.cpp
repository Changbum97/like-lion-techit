#include "../include/DailyAnalysis.h"

bool DailyAnalysis::isTargetData(string date) {
    bool res = false;
    res = date == this->date;

    return res;
}