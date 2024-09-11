#include <iostream>
#include <string>
using namespace std;

int main()
{
    int usa_temp;
    cout << "화씨온도: ";
    cin >> usa_temp;
    cout << "섭씨온도= " << (5.0/9.0)*(usa_temp-32) << endl;
    
    return 0;

}