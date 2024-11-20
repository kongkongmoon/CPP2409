#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

void displayMap(const vector<vector<int>>& map, int user_x, int user_y) {
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl << " -------------------------------- " << endl;
    }
}

void checkState(vector<vector<int>>& map, int& user_x, int& user_y, User& user) {
    switch (map[user_y][user_x]) {
        case 1: // 아이템
            cout << "아이템을 획득했습니다!" << endl;
            user.IncreaseItemCount();
            map[user_y][user_x] = 0;  // 아이템 획득 후 빈칸으로 변경
            break;
        case 2: // 적
            cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
            user.DecreaseHP(2);
            break;
        case 3: // 포션
            cout << "포션을 발견했습니다. HP가 2 늘어납니다." << endl;
            user.IncreaseHP(2);
            map[user_y][user_x] = 0;  // 포션 사용 후 빈칸으로 변경
            break;
        default:
            break;
    }
}

int main() {
    // Magician과 Warrior 생성
    Magician magician("마법사");
    Warrior warrior("전사");

    // 플레이어 상태
    vector<User*> players = {&magician, &warrior};
    int currentPlayer = 0; // 0: Magician, 1: Warrior
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    // 각 플레이어 위치
    vector<pair<int, int>> positions = {{0, 0}, {0, 0}}; // {x, y} 좌표

    while (true) {
        User* user = players[currentPlayer];
        int& user_x = positions[currentPlayer].first;
        int& user_y = positions[currentPlayer].second;

        cout << "\n현재 플레이어: " << (currentPlayer == 0 ? "마법사" : "전사") << endl;
        cout << *user << endl;

        cout << "명령어를 입력하세요 (up, down, left, right, map, attack, finish): ";
        string user_input;
        cin >> user_input;

        if (user_input == "up") {
            user_y -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            } else {
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "down") {
            user_y += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            } else {
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "left") {
            user_x -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            } else {
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "right") {
            user_x += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            } else {
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "attack") {
            user->DoAttack();
        } else if (user_input == "finish") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // HP 체크
        if (user->GetHP() <= 0) {
            cout << "\n" << (currentPlayer == 0 ? "마법사" : "전사") << "가 죽었습니다. 게임 종료." << endl;
            break;
        }

        // 턴 교체
        currentPlayer = 1 - currentPlayer;
    }

    return 0;
}
