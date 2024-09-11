#include <iostream>
#include <string>
using namespace std;

int main()
{
    int coin;
    int price;
    cout << "현재 가지고 있는 돈: ";
    cin >> coin;
    cout << "캔디의 가격: ";
    cin >> price;
    cout << "최대로 살 수 있는 캔디= " << coin/price << endl;
    cout << "캔디 구입 후 남은 돈= " << coin%price << endl;
    
    return 0;

}