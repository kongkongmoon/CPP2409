#include <iostream>
#include <string>
#include "user.h"  // User 클래스 헤더 파일 포함

using namespace std;

const int mapX = 5;
const int mapY = 5;

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
    return user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[mapY][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
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

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[mapY][mapX], int user_x, int user_y) {
    return map[user_y][user_x] == 4;
}

// 아이템, 적, 포션을 만났을 때의 동작을 처리하는 함수
void checkState(int map[mapY][mapX], int& user_x, int& user_y, User& user) {
    switch (map[user_y][user_x]) {
        case 1:
            {cout << "아이템이 있습니다. 포션의 위치로 이동하겠습니까? (1: 네 / 그 외: 아니오)" << endl;
            string answer;
            cin >> answer;
            if (answer == "1") {
                for (int i = 0; i < mapY; i++) {
                    for (int j = 0; j < mapX; j++) {
                        if (map[i][j] == 3) {
                            user_x = j;
                            user_y = i;
                            displayMap(map, user_x, user_y);
                            cout << "'네'를 선택하여 포션이 있는 곳으로 이동했습니다." << endl;
                            checkState(map, user_x, user_y, user);
                            return;
                        }
                    }
                }
            } else {
                cout << "'아니오'를 선택했습니다." << endl;
            }
            break;}
        case 2:
            cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
            user.DecreaseHP(2);
            break;
        case 3:
            cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
            user.IncreaseHP(2);
            break;
        default:
            break;
    }
}

// HP가 0 이하인지 체크하는 함수
bool CheckUser(User user) {
    return user.GetHP() > 0;
}

// 메인 함수
int main() {
    User user; // 유저 객체 생성

    int map[mapY][mapX] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    int user_x = 0, user_y = 0;

    while (true) {
        cout << "현재 HP: " << user.GetHP() << endl;
        cout << "명령어를 입력하세요 (up, down, left, right, map, finish): ";
        
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
                checkState(map, user_x, user_y, user);
            }
        } else if (user_input == "down") {
            user_y += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_y -= 1;
            } else {
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user);
            }
        } else if (user_input == "left") {
            user_x -= 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x += 1;
            } else {
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user);
            }
        } else if (user_input == "right") {
            user_x += 1;
            if (!checkXY(user_x, mapX, user_y, mapY)) {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
                user_x -= 1;
            } else {
                user.DecreaseHP(1);
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, user);
            }
        } else if (user_input == "map") {
            displayMap(map, user_x, user_y);
        } else if (user_input == "finish") {
            cout << "종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            break;
        }

        if (!CheckUser(user)) {
            cout << "HP가 0이 되어 게임에 실패했습니다." << endl;
            break;
        }
    }

    return 0;
}