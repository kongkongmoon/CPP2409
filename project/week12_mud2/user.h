#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
protected:
    int hp;       // 사용자 HP
    int itemCnt;  // 먹은 아이템 수

public:
    User(int initial_hp = 20);    // 생성자
    virtual ~User() = default;    // 가상 소멸자

    void DecreaseHP(int dec_hp);  // HP 감소
    void IncreaseHP(int inc_hp);  // HP 증가
    void IncreaseItemCount();     // 아이템 횟수 증가
    int GetHP() const;            // 현재 HP 반환
    int GetItemCount() const;     // 아이템 횟수 반환

    virtual void doAttack() const; // 공격 동작 (가상 함수)

    // 출력 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

class Magician : public User {
public:
    Magician();
    void doAttack() const override; // 마법 공격
};

class Warrior : public User {
public:
    Warrior();
    void doAttack() const override; // 베기 공격
};

#endif
