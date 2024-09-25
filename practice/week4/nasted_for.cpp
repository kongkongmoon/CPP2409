#include <iostream>
using namespace std;

int main(){
    cout << "구구단 출력: \n";
    
    for(int i=2; i<=9; ++i) {
        cout << i << "단:\n";

        for(int j=1; j<=9; ++j) {
            cout << i << " X " << j << " = "<< (i*j) << endl;
        }
    }
    return 0;

}