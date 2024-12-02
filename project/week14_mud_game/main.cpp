#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include "user.h"

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 맵 파일을 읽어와 벡터 초기화
vector<vector<int>> loadMap(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("맵 파일을 열 수 없습니다.");
    }

    vector<vector<int>> map(mapY, vector<int>(mapX));
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (!(file >> map[i][j])) {
                throw runtime_error("맵 파일 형식이 올바르지 않습니다."); //파일을 읽지 못 하면 예외
            }
        }
    }
    return map;
}

// 좌표가 유효한지 확인
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

// 맵 출력
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
        case 1:
            cout << "아이템을 획득했습니다!" << endl;
            user.IncreaseItemCount();
            map[user_y][user_x] = 0;
            break;
        case 2:
            cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
            user.DecreaseHP(2);
            break;
        case 3:
            cout << "포션을 발견했습니다. HP가 2 늘어납니다." << endl;
            user.IncreaseHP(2);
            map[user_y][user_x] = 0;
            break;
        default:
            break;
    }
}

bool CheckUser(const User& user) {
    return user.GetHP() > 0;
}

int main() {
    try {
        // 맵 파일 로드
        vector<vector<int>> map = loadMap("map.txt");

        // 유저 선택
        User* user = nullptr;
        cout << "직업을 선택하세요 (1: Magician, 2: Warrior): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            user = new Magician();
        } else if (choice == 2) {
            user = new Warrior();
        } else {
            cout << "잘못된 직업 선택입니다." << endl;  //1 또는 2가 아닌 것을 입력했을 때 예외 발생
        }

        user->DisplayInfo();

        // 게임 루프
        int user_x = 0, user_y = 0;
        while (true) {
            cout << "현재 HP: " << user->GetHP() << endl;
            displayMap(map, user_x, user_y);

            cout << "명령어를 입력하세요 (up, down, left, right, map, finish): ";
            string user_input;
            cin >> user_input;

            int prev_x = user_x, prev_y = user_y;
            if (user_input == "up") user_y--;
            else if (user_input == "down") user_y++;
            else if (user_input == "left") user_x--;
            else if (user_input == "right") user_x++;
            else if (user_input == "map") {
                displayMap(map, user_x, user_y);
                continue;
            } else if (user_input == "finish") {
                cout << "게임을 종료합니다." << endl;
                break;
            } else {
                cout << "잘못된 명령입니다." << endl;
                continue;
            }

            // 좌표 검사
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x = prev_x;
                user_y = prev_y;
            } else {
                user->DecreaseHP(1);  // 이동 시 HP 감소
                checkState(map, user_x, user_y, *user);
            }

            if (checkGoal(map, user_x, user_y)) {
                cout << "목적지에 도착했습니다! 게임을 종료합니다." << endl;
                break;
            }

            if (!CheckUser(*user)) {
                cout << "HP가 0입니다. 게임 오버!" << endl;
                break;
            }
        }

        delete user;

    } catch (const exception& e) {
        cerr << "오류: " << e.what() << endl;
    }

    return 0;
}
