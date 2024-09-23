#include <iostream>
using namespace std;

int main(){
    int number;
    cout << "숫자를 입력하시오: (0이상 정수)" << endl;
    cin >> number; //입력
    
    switch(number){
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "one" << endl;
            break;
        default:
            cout << "many" << endl;
            break;
    }
    return 0;

}