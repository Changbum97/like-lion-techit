#pragma once

#include "../include/AccountData.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class DataManager {

public:
    DataManager();
    void save();
    void load();
    void appendData(AccountData data) {
        accountData[data.getDate()].push_back(data);
    }
    map<string, vector<AccountData>> get() {
        return accountData;
    }

private:
    map<string, vector<AccountData>> accountData;
    string filename = "AccountBook.data";
}