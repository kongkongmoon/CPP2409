#include <iostream>
using namespace std;

int main(){
    long choice;
    
    cout << "do-while문을 사용하여 메뉴 선택:"; 

    do{
        cout << "메뉴를 선택하세요 (1. 옵션 1, 2. 옵션 2, 3. 종료): "; //입력안내
        cin >> choice; //입력
        switch(choice){
            case 1:
            cout << "옵션 1 선택\n";
            break;
            case 2:
            cout << "옵션 2 선택\n";
            break;
            case 3:
            cout << "프로그램 종료\n";
            break;
            default:
            cout << "잘못된 선택\n";
            break;
        }
    }while(choice!=3);

    return 0;

}