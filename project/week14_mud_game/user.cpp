#include "user.h"
#include <iostream>
using namespace std; // 예외 주석으로 달기

// Magician 클래스 정의
Magician::Magician() : hp(15), itemCnt(0) {}

void Magician::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

void Magician::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void Magician::IncreaseItemCount() {
    itemCnt += 1;
}

int Magician::GetHP() const {
    return hp;
}

int Magician::GetItemCount() const {
    return itemCnt;
}

void Magician::DisplayInfo() const {
    cout << "직업: Magician, 초기 HP: 15" << endl;
}

// Warrior 클래스 정의
Warrior::Warrior() : hp(20), itemCnt(0) {}

void Warrior::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

void Warrior::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void Warrior::IncreaseItemCount() {
    itemCnt += 1;
}

int Warrior::GetHP() const {
    return hp;
}

int Warrior::GetItemCount() const {
    return itemCnt;
}

void Warrior::DisplayInfo() const {
    cout << "직업: Warrior, 초기 HP: 20" << endl;
}
