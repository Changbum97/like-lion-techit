#pragma once

#include "DataAnalysis.h"

class YearlyAnalysis : public DataAnalysis {

public:
    virtual bool isTargetData(string date);
};