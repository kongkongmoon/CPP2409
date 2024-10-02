#include <iostream>
using namespace std;

#define WIDTH 9
#define HEIGHT 3

int main(){
    int table[HEIGHT][WIDTH];
    int r, c;

    for(int r=0; r<HEIGHT; r++){
        for( c=0; c<WIDTH; c++){
            table[r][c]= (r+1)*(c+1);
        }
    }

    for(int r=0; r<HEIGHT; r++){
        for( c=0; c<WIDTH; c++){
            cout << table[r][c] << ", ";
        }
        cout << endl;
    }
    return 0;
}