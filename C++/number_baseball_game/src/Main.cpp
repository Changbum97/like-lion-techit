#include <iostream>
#include "../include/BaseballGame.h"

using namespace std;

int main() {
    BaseballGame game;

    while(!game.isGameDone()) {
        game.initialize();  // 랜덤 숫자 생성
        
        while(game.getNumberOfStrike() < 3) {
            game.input();
            game.judge();       // Strike, Ball 판단
            game.output();
        }
    }

    cout << "게임 종료" << endl;

    return 0;
}