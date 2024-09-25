#include <iostream>
using namespace std;

int main(){
    long fact = 1;
    int n;
    
    cout << "정수를 입력하시오:"; //입력 안내
    cin >> n; //입력

    for(int i=1;i<=n;i++){ //n!계산
        fact = fact*i;
    }
    
    cout << n << "!은 "<< fact << "입니다\n"; //n!출력

    return 0;

}