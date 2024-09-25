#include <iostream>
using namespace std;

int main(){
    int userInput;
    
    cout << "정수를 10번 입력하세요(0을 입력하면 종료)"; //입력 안내
    cin >> userInput; //입력

    for(int i=1;i<=10;i++){ 
        if(userInput == 0){
            break;
        }
        cout << "입력값: "<<userInput<<" 횟수 :"<< i <<endl;     
    }
    
    cout << "종료되었습니다\n"; 

    return 0;

}