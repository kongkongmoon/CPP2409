#include <iostream>
using namespace std;

int main(){
    const int STUDENTS=5;
    int scores[STUDENTS];
    int sum=0;
    int i, average;

    for(int i=0; i<STUDENTS; i++){
        cout <<"학생들의 성적을 입력하세요 :";
        cin >> scores[i];
    }
    for(int i=0; i<STUDENTS; i++){
        sum+=scores[i];
    }
    average = sum/STUDENTS;
    cout <<"성적 평균= " << average << endl;
    return 0;

}