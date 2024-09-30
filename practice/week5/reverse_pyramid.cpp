#include <iostream>
using namespace std;

int main(){
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100): ";
    cin >> floor;

    for(int i=floor-1; i>=0; i--){ //i를floor대신floor-1로 설정함
        for(int j=0; j<floor-i+1;j++ ){
            cout <<"S";
        }
        for(int k=0; k<i*2+1; k++ ){ //여기 조건이 피라미드 조건과 같음
            cout <<"*";
        }
        cout << endl;
    }
    return 0;

}