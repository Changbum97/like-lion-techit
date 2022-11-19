#include "../include/DataManager.h"
#include <fstream>
#include <sstream>
#include <vector>

DataManager::DataManager() {

}

void DataManager::save() {
    ofstream outFile(filename);
    string line;

    if(outFile.is_open()) {
        /*
            INCOME type : date, type, amount
            OUTCOME type : date, type, name, category, amount
        */
        for(auto data_set : accountData) {
            for(auto data : data_set.second) {
                line = "";
                line += data.getDate();
                line += "," + to_string((int)data.getType());
                if(data.type == DATA_TYPE::OUTCOME) {
                    line += "," + data.getName();
                    line += "," + data.getCategory();
                }
                line += "," + to_string(data.getAmount());
                outFile << line << endl;
            }
        }
        outFile.close();
    } else {
        cout << filename << " can't be opened" << endl;
    }
}

void DataManager::load() {
    ifstream inFile(filename);
    string line;

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            stringstream ss(line);
            string token;
            vector<string> strVector;

            // date, type, name, category, amount
            while(getline(ss, token, ',')) {
                strVector.push_back(token);

            }
            stringstream type(vector[1]);
            int itype;
            type >> itype;

            if(itype == DATA_TYPE::INCOME) {
                stringstream amount(strVector[2]);
                int iamount;
                amount >> iamount;

                AccountData data(
                    strVector[0],
                    (DATA_TYPE)itype,
                    iamount);

                accountData[strVector[0]].push_back(data);

            } else if(itype == DATA_TYPE::OUTCOME) {
                stringstream amount(strVector[2]);
                int iamount;
                amount >> iamount;

                AccountData data(
                    strVector[0],
                    (DATA_TYPE)itype,
                    iamount,
                    strVector[2],
                    strVector[3]);
                    
                accountData[strVector[0]].push_back(data);
            }
        }
        inFile.close();
    } else {
        cout << filename << " can't be opened" << endl;
    }
}