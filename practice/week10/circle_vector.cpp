#include <iostream>
#include <vector>
using namespace std;

class Circle
{
public:
    int x, y;
    int radius;
    Circle()
    {x = 0; y = 0; radius = 0;}
    Circle(int x, int y, int r) {
        this->x = x;
        this->y = y;
        this->radius = r;
    }
    void Print() {
        cout << "반지름: " << radius << " (" << x << ", " << y << ")" << endl;
    }  //@를 빼고 했는데 악성코드로 걸려서 검사를 끄고 실행시켰는데 잘 된건지 모르겠어요.
};

int main(void) {
    vector<Circle> objArray;
    for (int i = 0; i < 10; i++) {
        Circle obj{rand() % 300, rand() % 300, rand() % 100};
        objArray.push_back(obj);
    }
    for (Circle c : objArray) {c.Print();}
    
    return 0;
}