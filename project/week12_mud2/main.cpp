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

bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y) {
    return map[user_y][user_x] == 4;
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

bool CheckUser(const User& user) {
    return user.GetHP() > 0;
}

void moveUser(const string& user_input, int& user_x, int& user_y, User& user, const vector<vector<int>>& map) {
    int prev_x = user_x;
    int prev_y = user_y;

    if (user_input == "up") user_y--;
    else if (user_input == "down") user_y++;
    else if (user_input == "left") user_x--;
    else if (user_input == "right") user_x++;
    else return;

    if (!checkXY(user_x, mapX, user_y, mapY)) {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        user_x = prev_x;
        user_y = prev_y;
    } else {
        user.DecreaseHP(1);  // 이동 시 HP 감소
    }
}

int main() {
    Magician magician;
    Warrior warrior;

    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int magician_x = 0, magician_y = 0;
    int warrior_x = 4, warrior_y = 4;
    bool magician_turn = true;

    while (true) {
        User& current_user = magician_turn ? static_cast<User&>(magician) : static_cast<User&>(warrior);
        int& user_x = magician_turn ? magician_x : warrior_x;
        int& user_y = magician_turn ? magician_y : warrior_y;

        cout << (magician_turn ? "Magician" : "Warrior") << "의 차례입니다!" << endl;
        cout << "현재 HP: " << current_user.GetHP() << endl;
        displayMap(map, user_x, user_y);

        cout << "명령어를 입력하세요 (up, down, left, right, map, finish): ";
        string user_input;
        cin >> user_input;

        if (user_input == "finish") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else {
            moveUser(user_input, user_x, user_y, current_user, map);
            checkState(map, user_x, user_y, current_user);
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << (magician_turn ? "Magician" : "Warrior") << "이(가) 목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        if (!CheckUser(magician)) {
            cout << "Magician의 HP가 0입니다. Warrior가 승리했습니다!" << endl;
            break;
        } else if (!CheckUser(warrior)) {
            cout << "Warrior의 HP가 0입니다. Magician이 승리했습니다!" << endl;
            break;
        }

        magician_turn = !magician_turn;  // 턴 교대
    }

    cout << "게임 종료!" << endl;
    return 0;
}
