#include "DataAnalysis.h"

class DailyAnalysis : public DataAnalysis {
public:
    virtual bool isTargetData(string date);
};