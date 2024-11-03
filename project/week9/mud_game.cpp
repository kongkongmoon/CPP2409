#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
const int userHP = 20; // 체력

// 사용자 정의 함수
// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[mapY][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6칸 공백
					break;
				case 1:
					cout << "아이템|";
					break;
				case 2:
					cout << "  적  |"; // 양 옆 2칸 공백
					break;
				case 3:
					cout << " 포션 |"; // 양 옆 1칸 공백
					break;
				case 4:
					cout << "목적지|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[mapY][mapX], int user_x, int user_y) {
	// 목적지 도착하면
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 아이템, 적 포션을 만났을 때의 그에 대한 기능을 동작 및 메시지출력 함수
void checkState(int map[mapY][mapX], int& user_x, int& user_y, int& hp) {
    int position = map[user_y][user_x];
    switch (position) {
        case 1: // 아이템을 만났을 때
            {cout << "아이템이 이있습니다. 포션의 위치로 이동하겠습니까? (1: 네 / 그 외: 아니오)" << endl;
            // 포션 위치로 이동
            string answer = "";
            cin >> answer;
            if (answer == "1"){
                for (int i = 0; i < mapY; i++) {
                    for (int j = 0; j < mapX; j++) {
                        if (map[i][j] == 3) { // 포션 위치 찾기
                            user_x = j;
                            user_y = i;
                            displayMap(map, user_x, user_y);
                            cout << "'네'를 선택하여 포션이 있는 곳으로 이동했습니다." << endl;
                            checkState(map, user_x, user_y, hp);
                            return;
                        }
                    }
                }
            }
            else {
                cout << "'아니오'를 선택했습니다." << endl;
                return;
            }
            break;}
        case 2: // 적을 만났을 때
            cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
            hp -= 2;
            break;
        case 3: // 포션을 만났을 때
            cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
            hp += 2;
            break;
        default:
            break;
    }
}


// 메인 함수
int main() {
    int hp = userHP; // 유저의 초기 체력

    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = { {0, 1, 2, 0, 4},
                            {1, 0, 0, 2, 0},
                            {0, 0, 0, 0, 0},
                            {0, 2, 3, 0, 0},
                            {3, 0, 0, 0, 2} };

    // 유저의 위치를 저장할 변수
    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호

    // 게임 시작
    while (true) { // 사용자에게 계속 입력받기 위한 무한 루프
        
        //사용자가 입력을 저장할 변수
        string user_input = "";

        cout << "현재 HP: " << hp << endl; // 현재 체력 표시
        cout << "명령어를 입력하세요 (up, down, left, right, map, finish): ";
        cin >> user_input;

        if (user_input == "up") {
            // 위로 한 칸 올라가기
            user_y -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
            else {
                cout << "위로 한 칸 올라갑니다." << endl;
                hp -= 1;
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, hp);
            }
        }
        else if (user_input == "down") {
            // 아래로 한 칸 내려가기
            user_y += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
            else {
                cout << "아래로 한 칸 내려갑니다." << endl;
                hp -= 1;
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, hp);
            }
        }
        else if (user_input == "left") {
            // 왼쪽으로 이동하기
            user_x -= 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
            else {
                cout << "왼쪽으로 이동합니다." << endl;
                hp -= 1;
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, hp);
            }
        }
        else if (user_input == "right") {
            user_x += 1;
            bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
            else {
                cout << "오른쪽으로 이동합니다." << endl;
                hp -= 1;
                displayMap(map, user_x, user_y);
                checkState(map, user_x, user_y, hp);
            }
        }
        else if (user_input == "map") {
            //지도 보여주기 함수 호출
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "finish") {
            cout << "종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // 목적지에 도달했는지 체크
        // 목적지에 도착하면 HP가 0이어도 성공으로 간주
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // HP가 0인지 확인 후 게임 종료
        if (hp <= 0) {
            cout << "HP가 0 이하가 되었습니다. 실패했습니다." << endl;
            break;
        }
    }
    return 0;
}