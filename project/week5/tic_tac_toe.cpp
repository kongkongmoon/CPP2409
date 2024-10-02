#include <iostream>
using namespace std;

int main(){
    const int numCell = 3;
    char board[numCell][numCell]{};
    int x, y; // 사용자에게 입력받는 x, y 좌표를 저장할 변수
    
    // 보드판 초기 화
    for (x = 0; x < numCell; x++) {
        for (y = 0; y < numCell; y++) {
            board[x][y] = ' ';
        }
    }

    // 게임하는 코드
    int k= 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 문자 변수
    while (true) {
        //1. 누구 차례인지 출력
        switch (k % 2) {
        case 0:
            cout << "첫번째 유저(x)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "두번째 유저(0)의 차례입니다 -> ";
            currentUser = '0';
            break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        if (y >= numCell || x >= numCell) {
            cout << x << ", " << y << ": ";
            cout <<" X와 y둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[y][x] !=' ') {
        cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
        continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 통기
        board[y][x] = currentUser;
    
        // 5. 현재 보드 판 출력
        for (int i = 0; i < numCell; i++) {
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++) {
                cout<< board[i][j];
                if (j == numCell - 1) {
                    break;
                }
                cout << "  |";
                }
                cout << endl;
        }
        cout << "---|---|---" << endl;
        k++;

        // 빙고 시 승자 출력 후 종료 (가로 세로 대각선 비교 but 빈칸일 때도 작동하는 오류)
        /*00 10 20
          01 11 21
          02 12 22*/
        if(k>=5){
        if(((board[0][0]==board[0][1]) && (board[0][1]==board[0][2])) || ((board[1][0]==board[1][1]) && (board[1][1]==board[1][2])) || ((board[2][0]==board[2][1]) && (board[2][1]==board[20][2]))){
            cout << "가로로 한줄이 완성되었습니다. 유저("<< currentUser << ")의 승리입니다. 게임을 종료합니다." << endl;
            break;
        }else if(((board[0][0]==board[1][0]) && (board[1][0]==board[2][0])) || ((board[0][1]==board[1][1]) && (board[1][1]==board[2][1])) ||((board[0][2]==board[1][2]) && (board[1][2]==board[2][2]))){
            cout << "세로로 한줄이 완성되었습니다. 유저("<< currentUser << ")의 승리입니다. 게임을 종료합니다." << endl;
            break;
        }else if(((board[0][0]==board[1][1]) && (board[1][1]==board[2][2])) || ((board[2][0]==board[1][1]) && (board[1][1]==board[0][2]))) {
            cout <<" 대각선으로 한줄이 완성되었습니다. 유저("<< currentUser << ")의 승리입니다. 게임을 종료합니다." << endl;
            break;
        }}
        
        // 모든 칸이 찼으면 종료
        if(k==9){
            cout << "모든 칸이 찼음니다. 게임을 종료합니다." << endl;
            break;
        }

    }
    return 0;
}