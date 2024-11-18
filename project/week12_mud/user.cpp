#include "user.h"

User::User() : hp(20), itemCnt(0) {}  // 초기 HP와 아이템 횟수 설정

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

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << "이고, 먹은 아이템은 총 " << user.GetItemCount() << "개입니다.";
    return os;
}
