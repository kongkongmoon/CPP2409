#include <iostream>
using namespace std;

class Person
{
protected: 
    string name; 
    string address;
};

class Student : public Person 
{
public:
    void SetAddress(string add)
    {
        address = add;
    }
    string GetAddress()
    {
        return address;
    }
    void SetName(string name)
    {
        this->name = name;
    }
    string GetName()
    {
        return name;
    }
};

int main()
{
    Student obj;
    obj.SetName("미수");
    cout << "이름: " << obj.GetName() << endl;

    obj.SetAddress("서울시 종로구 1번지");
    cout << "주소: " << obj.GetAddress() << endl;

    return 0;
}
