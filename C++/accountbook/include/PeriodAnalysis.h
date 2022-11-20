#pragma once

#include "DataAnalysis.h"

class PeriodAnalysis : public DataAnalysis {

public:
    virtual bool isTargetData(string date);
};