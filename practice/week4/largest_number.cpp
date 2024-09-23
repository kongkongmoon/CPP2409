#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;
    
    cout << "3개의 정수를 입력하시오: "; //입력 안내
    cin >> a >> b >> c; //입력
    
    if(a>b&&a>c){ //비교(같은수가 있을 경우는 오류발생)
        largest = a;
    }
    else if(b>a&&b>c){
        largest = b;
    }
    else{
        largest = c;
    }

    cout <<"가장 큰 정수는" << largest << endl;
    return 0;

}