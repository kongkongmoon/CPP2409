#include <iostream>
using namespace std;

int main(){
    int a, b, c, largest;
    
    cout << "3개의 정수를 입력하시오: "; //입력 안내
    cin >> a >> b >> c; //입력
    
    if(a>b){ //같은 수가 나올때는 바르게 작동하지 않음
        if(a>c){ 
        largest = a;
        }
        else{
        largest = c;
        }
    }
    else if(b>a){
        if(b>c){ 
        largest = b;
        }
        else{
        largest = c;    
    }
    }
    

    cout <<"가장 큰 정수는" << largest << endl;
    return 0;

}