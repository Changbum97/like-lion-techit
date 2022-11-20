#pragma once

#include "DataManager.h"
#include "DataAnalysis.h"
#include "PeriodAnalysis.h"
#include "YearlyAnalysis.h"
#include "MonthlyAnalysis.h"
#include "DailyAnalysis.h"

enum class MENU {
    NONE,   // 0부터 시작
    INPUT,
    SPA,
    TERMINATE,
    LAST
};

enum class INPUT_MENU {
    NONE,
    INCOME,
    OUTCOME,
    LAST
};

class AccountBook {

public:
    AccountBook();
    MENU printAndGetMenu();
    bool isProgramTerminate();
    INPUT_MENU printAndGetInputMenu();
    void runInput(INPUT_MENU inputMenu);
    void runSPA();
    void setProgramTerminate();
    void initialize();

private:
    bool isTerminate;
    DataManager dataManager;
    DataAnalysis* dataAnalysis;
    PeriodAnalysis periodAnalysis;
    YearlyAnalysis yearlyAnalysis;
    MonthlyAnalysis monthlyAnalysis;
    DailyAnalysis dailyAnalysis;
};