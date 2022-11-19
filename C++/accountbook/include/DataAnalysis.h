#pragma once

#include <string>
#include <map>
#include <vector>

using namespace std;

enum class ANALYSIS_MODE {
    NONE,
    NETCOME,
    CATEGORY_COME,
    LAST
}

enum class ANALYSIS_TYPE {
    NONE,
    PERIOD,
    YEARLY,
    MONTHLY,
    DAILY,
    LAST
}

class DataAnalysis {
public:
    DataAnalysis() {
        analysisDataIncome.reverse(ANALYSIS_TYPE::LAST);
        analysisDataOutcome.reverse(ANALYSIS_TYPE::LAST);
        analysisDataOutcomeByCategory.reverse(ANALYSIS_TYPE::LAST);
    }
    void selectTarget(string date, string date_end = "");
    void analyze(ANALYSIS_TYPE type, ANALYSIS_MODE mode);
    void makeAnalysisData(ANALYSIS_TYPE type, ANALYSIS_MODE mode,
                          map<string, vector<AccountData>> data);

public:
    string date;
    string date_end;
    vector<map<string, int>> analysisDataIncome;
    vector<map<string, int>> analysisDataOutcome;
    vectro<map<string, map<string, int>>> analysisDataOutcomeByCategory;
}