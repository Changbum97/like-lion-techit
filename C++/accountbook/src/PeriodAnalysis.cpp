#include "../include/PeriodAnalysis.h"

bool PeriodAnalysis::isTargetData(string date) {
    bool res = false;
    res = this->date <= date;
    res = res && (date <= this->date_end);

    return res;
}