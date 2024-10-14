#include <iostream>
#include <string>
using namespace std;

string toLowerStr(string str){
    for(int i = 0; i < str.length(); i++){
        if(str[i]>64 && str[i]<91)
        str[i] = str[i]-32;
        }
        return str;
}

string toUpperStr(string str){
     for(int i = 0; i < str.length(); i++){
        if(str[i]>96 && str[i]<123)
        str[i] = str[i]+32;
        }
        return str;
}

int calcHammingDist(string s1, string s2){
    s2 = toLowerStr(s2);
    int count = 0;
    for(int i = 0; i < s1.length(); i++){
            if(s1[i] != s2[i])
                count += 1;
        }
        return count;
}

int main(){
    string s1, s2 = "Hello, World";

    do{
    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;}
    while(s1.length()!=s2.length());

    int count = calcHammingDist(s1,s2);
    cout << "해밍 거리는 "<< count <<endl;
    

    return 0;
}