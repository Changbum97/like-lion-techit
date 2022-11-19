#pragma once

#include <string>

using namespace std;

enum class DATA_TYPE {
    NONE,
    INCOME,
    OUTCOME,
    LAST
}

class AccountData {

public:
    AccountData(
        string date,
        DATA_TYPE type,
        int amount,
        string name = "",
        string category = "");
    
    string getDate() {
        return date;
    }
    DATA_TYPE getType() {
        return type;
    }
    string getName() {
        return name;
    }
    string getCategory() {
        return category;
    }
    int getAmount() {
        return amount;
    }

private:
    string date;
    DATA_TYPE type;
    string name;
    string category;
    int amount;

}