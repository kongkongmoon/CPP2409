#include <iostream>
#include <time.h>
using namespace std;

int main(){
    int i;
    int ans;
    cout << "산수 문제를 자동으로 출제합니다\n";
    
    while(true){
    int firstNum=rand() %100;
    int secondNum=rand() %100;    
    
    cout << firstNum<<"+" <<secondNum << "="; 
    cin >> ans;

    if(firstNum+secondNum==ans){ 
        cout << "맞았습니다.\n";
        break;
    }
    else{
        cout << "틀렸습니다.\n";
    }
    
    }
    return 0;

}

