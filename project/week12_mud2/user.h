#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

// Base User Class
class User {
protected:
    int hp;          // 캐릭터의 HP
    string name;     // 캐릭터 이름
    int itemCount;   // 획득한 아이템 수

public:
    User(string name, int hp = 10) : name(name), hp(hp), itemCount(0) {}
    virtual ~User() {}

    // HP 및 아이템 관리
    int GetHP() const { return hp; }
    void DecreaseHP(int amount) { hp = max(0, hp - amount); }
    void IncreaseHP(int amount) { hp += amount; }
    void IncreaseItemCount() { itemCount++; }
    int GetItemCount() const { return itemCount; }

    // 공격 동작
    virtual void DoAttack() const {
        cout << name << ": 공격합니다!" << endl;
    }

    // 출력 연산자 오버로드
    friend ostream& operator<<(ostream& os, const User& user) {
        os << "이름: " << user.name << ", HP: " << user.hp
           << ", 아이템 수: " << user.itemCount;
        return os;
    }
};

// Magician Class (Derived from User)
class Magician : public User {
public:
    Magician(string name) : User(name) {}

    void DoAttack() const override {
        cout << name << ": 마법 사용!" << endl;
    }
};

// Warrior Class (Derived from User)
class Warrior : public User {
public:
    Warrior(string name) : User(name) {}

    void DoAttack() const override {
        cout << name << ": 베기 사용!" << endl;
    }
};

#endif
