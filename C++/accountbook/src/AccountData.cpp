#include "../include/AccountData.h"

AccountData::AccountData(
    string date,
    DATA_TYPE type,
    int amount,
    string name,
    string category) {

        this->date = date;
        this->type = type;
        this->amount = amount;
        if(type == DATA_TYPE::OUTCOME) {
            this->name = name;
            this->category = category;
        }
}