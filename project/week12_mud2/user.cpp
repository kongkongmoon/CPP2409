#include "user.h"

// User 클래스
User::User(int initial_hp) : hp(initial_hp), itemCnt(0) {}

void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
}

void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
}

void User::IncreaseItemCount() {
    itemCnt += 1;
}

int User::GetHP() const {
    return hp;
}

int User::GetItemCount() const {
    return itemCnt;
}

void User::doAttack() const {
    std::cout << "공격합니다!" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "현재 HP: " << user.GetHP() << ", 먹은 아이템 수: " << user.GetItemCount();
    return os;
}

// Magician 클래스
Magician::Magician() : User(20) {} // 초기 HP는 20
void Magician::doAttack() const {
    std::cout << "마법 사용!" << std::endl;
}

// Warrior 클래스
Warrior::Warrior() : User(20) {} // 초기 HP는 20
void Warrior::doAttack() const {
    std::cout << "베기 사용!" << std::endl;
}
