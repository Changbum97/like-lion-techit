#include "../include/DataAnalysis.h"
#include <iostream>

using namespace std;

void DataAnalysis::selectTarget(string date, string date_end) {
    this->date = date;
    this->date_end = date_end;
    this->dateKey = date + date_end;
}
void DataAnalysis::analyze(ANALYSIS_MODE mode) {
    
   switch(mode) {
        case 1:  //ANALYSIS_MODE::NETCOME:
            {
                /* mode == ANALYSIS_MODE::NETCOME
                Total Income : 1000000
                Total Outcome : 650000
                Your Spend Rate : 65%
                특정 % 이상 => You have spent a lot
                특정 % 미만 => You are saving well
                */
                int spend_rate = (100 * analysisDataIncome[dateKey]) / analysisDataOutcome[dateKey];

                cout << "Total Income : ";
                cout << analysisDataIncome[dateKey] << endl;
                cout << "Total Outcome : ";
                cout << analysisDataOutcome[dateKey] << endl;
                cout << "Your Spend Rate : ";
                cout << spend_rate << "%" << endl;
                if(spend_rate > wasteRate) {
                    cout << "You have spent a lot" << endl;
                } else {
                    cout << "You are saving well" << endl;
                }
            }
            break;
        case 2:  //ANALYSIS_MODE::CATEGORY_COME:
            {
                /*
                Category
                You have spent 얼마 at 카테고리 이름(퍼센티지%) at most
                */
                int maxSpendMoney = 0;
                string maxSpendCategoryName = "";
                for(auto data : analysisDataOutcomeByCategory[dateKey]) {
                    if(data.second > maxSpendMoney) {
                        maxSpendMoney = data.second;
                        maxSpendCategoryName = data.first;
                    }
                }
                int spend_rate = (100 * maxSpendMoney) / analysisDataIncome[dateKey];
                cout << "Category" << endl;
                cout << "You have spent ";
                cout << maxSpendMoney << " at";
                cout << maxSpendCategoryName << "(";
                cout << spend_rate << ") at most" << endl;
            }
            break;
        default:
            break;
   }
}
void DataAnalysis::makeAnalysisData(ANALYSIS_MODE mode, map<string, vector<AccountData> > data) {

    analysisDataIncome[dateKey] = 0;
    analysisDataOutcome[dateKey] = 0;
    for(auto p : data) {
        if(!isTargetData(p.first)) continue;
        for(auto val : p.second) {
            analysisDataOutcomeByCategory[dateKey][val.getCategory()] = 0;
        }
    }
    
    for(auto p : data) {
        if(!isTargetData(p.first)) continue;

        for(auto val : p.second) {
            switch(val.getType()) {
                case 1:  //DATA_TYPE::INCOME:
                    analysisDataIncome[dateKey] += val.getAmount();
                    break;
                case 2:  //DATA_TYPE::OUTCOME:
                    switch(mode) {
                        case 1:  //ANALYSIS_MODE::NETCOME:
                            analysisDataOutcome[dateKey] += val.getAmount();
                            break;
                        case 2:  //ANALYSIS_MODE::CATEGORY_COME:
                            analysisDataOutcomeByCategory[dateKey][val.getCategory()] += val.getAmount();
                            break;
                        default:
                            break;
                    }
            }
        }
    }
}