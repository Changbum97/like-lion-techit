#include "../include/BaseballGame.h"
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

BaseballGame::BaseballGame() {
    answerNumberString = "";
    userNumberString = "";
    userNumberString = "";
    userNumberString = "";    
    numOfStrike = 0;
    numOfBall = 0;
    m_isGameDone = false;
}

bool BaseballGame::isGameDone() {
    if(m_isGameDone == true) return true;
    else return false;
}

void BaseballGame::initialize() {
    numOfStrike = 0;
    numOfBall = 0;
    answerNumberString = "";
    userNumberString = "";
    srand(time(NULL));
    generate3DigitRandomNumber();
}

int BaseballGame::getNumberOfStrike() {
    return numOfStrike;
}

bool BaseballGame::isNumber(char ch) {
    if(ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

bool BaseballGame::isInputNumberWrong() {
    if(userNumberString.size() != 3) {
        return true;
    } else {
        for(int i = 0 ; i < 3 ; i ++) {
            if(!isNumber(userNumberString[i])) {
                return true;
            }
        }
    }

    return false;
}

void BaseballGame::input() {
    userNumberString = "";
    while(isInputNumberWrong()) {
        cout << "3자리 숫자를 입력해주세요." << endl;
        cin >> userNumberString;
    }
}

void BaseballGame::judge() {
    numOfStrike = 0;
    numOfBall = 0;

    for(int i = 0 ; i < 3 ; i ++) {
        for(int j = 0 ; j < 3 ; j ++) {
            if(userNumberString[i] == answerNumberString[j]) {
                if(i == j) numOfStrike ++;
                else numOfBall ++;
            }
        }
    }
}

void BaseballGame:: output() {
    cout << "Strike(" << numOfStrike << "), Ball(" << numOfBall << ")" << endl;
    if(numOfStrike == 3) {
        cout << "숫자를 맞추셨습니다." << endl;
        cout << "한 판 더 하시겠습니까? (Y/N)" << endl;
        
        char yOrN;
        cin >> yOrN;

        if(yOrN == 'Y' || yOrN == 'y') {
            m_isGameDone = false;
        } else if(yOrN == 'N' || yOrN == 'n') {
            m_isGameDone = true;
        }
    }
}

void BaseballGame::generate3DigitRandomNumber() {

    bool hasNumber[10] = {false};
    int number;

    number = rand() % 10;
    answerNumberString += to_string(number);
    hasNumber[number] = true;

    while(hasNumber[number]) {
        number = rand() % 10;
    }
    answerNumberString += to_string(number);
    hasNumber[number] = true;

    while(hasNumber[number]) {
        number = rand() % 10;
    }
    answerNumberString += to_string(number);
    hasNumber[number] = true;
}