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

int main() {
    User* user = nullptr;
    cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        user = new Magician(); // Magician의 초기 체력은 15
    } else if (choice == 2) {
        user = new Warrior(); // Warrior의 초기 체력은 20
    } else {
        cout << "잘못된 선택입니다. 게임을 종료합니다." << endl;
        return 0;
    }

    user->DisplayInfo();

    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int user_x = 0, user_y = 0;

    while (true) {
        cout << "현재 HP: " << user->GetHP() << endl;
        cout << "명령어를 입력하세요 (up, down, left, right, map, finish): ";
        
        string user_input;
        cin >> user_input;

        if (user_input == "up") {
            user_y -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y += 1;
            } else {
                user->DecreaseHP(1);  // 이동 시 HP 1 감소
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "down") {
            user_y += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            } else {
                user->DecreaseHP(1);  // 이동 시 HP 1 감소
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "left") {
            user_x -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            } else {
                user->DecreaseHP(1);  // 이동 시 HP 1 감소
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "right") {
            user_x += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            } else {
                user->DecreaseHP(1);  // 이동 시 HP 1 감소
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, *user);
            }
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "finish") {
            break;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 게임을 종료합니다." << endl;
            break;
        }
        if (!CheckUser(*user)) {
            cout << "HP가 0입니다. 게임을 종료합니다." << endl;
            break;
        }
    }

    delete user;
    return 0;
}
