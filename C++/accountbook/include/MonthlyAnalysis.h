#include "DataAnalysis.h"

class MonthlyAnalysis : public DataAnalysis {

public:
    virtual bool isTargetData(string date);
};