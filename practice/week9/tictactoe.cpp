#include <iostream>
using namespace std;

const int numCell = 4; //새로 만든 함수에서도 쓰기 위해서 메인함수 밖으로 옮김

void isValid(int x, int y, char board[][numCell]) {
    if (x >= numCell || y >= numCell || x < 0 || y < 0) { // 좌표 범위를 벗어날 때
        cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return;
    }
    if (board[x][y] != ' ') { // 좌표의 입력값이 중복될 때
        cout << x << "," << y << ": 이미 돌이 차 있습니다." << endl;
        return;
    }
}

bool checkWin(char board[][numCell], char currentUser) {
    bool isWin = false;

    // 6.1. 가로/세로 돌 체크하기
    for (int i = 0; i < numCell; i++) {
        // 가로 체크
        isWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) {
                isWin = false;
                break;
            }
        }
        if (isWin) {
            cout << "가로에 모두 돌이 놓였습니다!!" << endl;
            return true;
        }

        // 세로 체크
        isWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[j][i] != currentUser) {
                isWin = false;
                break;
            }
        }
        if (isWin) {
            cout << "세로에 모두 돌이 놓였습니다!!" << endl;
            return true;
        }
    }

    // 6.2. 대각선 체크하기
    // 왼쪽 위에서 오른쪽 아래 대각선
    isWin = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) {
            isWin = false;
            break;
        }
    }
    if (isWin) {
        cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }

    // 오른쪽 위에서 왼쪽 아래 대각선
    isWin = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][numCell - 1 - i] != currentUser) {
            isWin = false;
            break;
        }
    }
    if (isWin) {
        cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
        return true;
    }

    return false;
}

int main() {
    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
    char board[numCell][numCell]; // 보드판을 나타내는 2차원 배열

    // 보드판 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    while (true) {
        // 1. 누구 차례인지 출력
        switch (k % 3) {
        case 0:
            currentUser = 'X';
            break;
        case 1:         
            currentUser = 'O';
            break;
        case 2:         
            currentUser = 'H';
            break;
        }
        cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        int x, y;
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        isValid(x, y, board);

        // 입력 좌표가 유효한지 확인 후 다음 단계 진행
        if (x >= numCell || y >= numCell || x < 0 || y < 0 || board[x][y] != ' ') continue;

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            for (int k=0; k< numCell; k++){
                if(k == (numCell-1))
                    {cout << "---" << endl;
                    }
                else cout << "---|";
            }
            for (int j = 0; j < numCell; j++)
            {
                cout << board[i][j];
                if (j == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        for (int k=0; k< numCell; k++){
                if(k == (numCell-1))
                    {cout << "---" << endl;
                    }
                else cout << "---|";
            }

        // 6. 승리 조건 체크
        if (checkWin(board, currentUser)) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 7. 모든 칸이 다 찼는지 체크하기
        int checked = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    checked++;
                }
            }
        }
        if (checked == 0) {
            cout << "모든 칸이 다 찼습니다. 게임을 종료합니다." << endl;
            break;
        }

        k++; // 다음 사용자로 턴 이동
    }

    return 0;
}