#include "user.h"

// User 클래스 생성자
User::User(string name, int hp) : name(name), hp(hp), itemCount(0) {}

// User 클래스 소멸자
User::~User() {}

// User 클래스 멤버 함수 정의
void User::DecreaseHP(int amount) {
    hp = max(0, hp - amount);
}

void User::IncreaseHP(int amount) {
    hp += amount;
}

void User::IncreaseItemCount() {
    itemCount++;
}

int User::GetHP() const {
    return hp;
}

int User::GetItemCount() const {
    return itemCount;
}

void User::DoAttack() const {
    cout << name << ": 공격합니다!" << endl;
}

// Magician 클래스의 DoAttack 재정의
void Magician::DoAttack() const {
    cout << name << ": 마법 사용!" << endl;
}

// Warrior 클래스의 DoAttack 재정의
void Warrior::DoAttack() const {
    cout << name << ": 베기 사용!" << endl;
}

// 출력 연산자 오버로드
ostream& operator<<(ostream& os, const User& user) {
    os << "이름: " << user.name << ", HP: " << user.hp
       << ", 아이템 수: " << user.itemCount;
    return os;
}
