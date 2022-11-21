#pragma once

#include <string>
#include <map>
#include <vector>
#include "AccountData.h"

using namespace std;

enum class ANALYSIS_MODE {
    NONE,
    NETCOME,
    CATEGORY_COME,
    LAST
};

enum class ANALYSIS_TYPE {
    NONE,
    PERIOD,
    YEARLY,
    MONTHLY,
    DAILY,
    LAST
};

class DataAnalysis {
public:
    DataAnalysis() {
    }
    void selectTarget(string date, string date_end = "");
    void analyze(ANALYSIS_MODE mode);
    void makeAnalysisData(ANALYSIS_MODE mode, map<string, vector<AccountData> > data);
    virtual bool isTargetData(string date) = 0;

public:
    int wasteRate = 60;
    string date;
    string date_end;
    string dateKey;
    map<string, int> analysisDataIncome;
    map<string, int> analysisDataOutcome;
    map<string, map<string, int> > analysisDataOutcomeByCategory;
};