#include <iostream>
#include <string>
using namespace std;

int main(){
    const int maxPeople =5;
    string names[maxPeople];
    int ages[maxPeople];
    string highName, lowName;
    int highAge=0;
    int lowAge =1000;

    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl; //입력 안내

    for(int i=0; i<maxPeople; i++){ //정보 입력
        cout << "사람" << i+1 << "의 이름: ";
        cin >> names[i];
        cout << "사람" << i+1 << "의 나이: ";
        cin >> ages[i];
    }

    int choice;
    bool b=true;

    while(b){
    cout << "1. 가장 나이가 많은 사람 출력 " << endl; //메뉴 출력
    cout << "2. 가장 나이가 적은 사람 출력" << endl;
    cout << "3. 종료 " << endl;
    cin >> choice; //입력

    switch(choice){ //같은 때는 먼저 적은 사람 한명만 출력됨
        case 1: //나이가 가장 많은 사람
            for(int i=0; i<maxPeople; i++){ 
            if(highAge<ages[i]){
                highName=names[i];
                highAge=ages[i];
            }
        }
        cout << "가장 나이가 많은 사람은 " << highName << "입니다.\n\n";
            break;
        case 2: //나이가 가장 적은 사람
            for(int i=0; i<maxPeople; i++){
            if(lowAge>ages[i]){
                lowName=names[i];
                lowAge=ages[i];
            }
        }
        cout << "가장 나이가 적은 사람은" << lowName << "입니다.\n\n";
            break;
        case 3:
            cout << "종료합니다." << endl;
            b=false;
            break;
        default:
            cout << "잘못된 선택입니다." << endl;
            break;
    }}
    return 0;

}