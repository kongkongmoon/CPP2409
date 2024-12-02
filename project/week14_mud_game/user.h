#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

class User {
public:
    virtual ~User() = default;
    virtual void DecreaseHP(int dec_hp) = 0;  // HP 감소
    virtual void IncreaseHP(int inc_hp) = 0;  // HP 증가
    virtual void IncreaseItemCount() = 0;     // 아이템 횟수 증가
    virtual int GetHP() const = 0;            // 현재 HP 반환
    virtual int GetItemCount() const = 0;     // 아이템 횟수 반환
    virtual void DisplayInfo() const = 0;     // 직업 정보 출력
};

class Magician : public User {
private:
    int hp;
    int itemCnt;

public:
    Magician();
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    void IncreaseItemCount() override;
    int GetHP() const override;
    int GetItemCount() const override;
    void DisplayInfo() const override;
};

class Warrior : public User {
private:
    int hp;
    int itemCnt;

public:
    Warrior();
    void DecreaseHP(int dec_hp) override;
    void IncreaseHP(int inc_hp) override;
    void IncreaseItemCount() override;
    int GetHP() const override;
    int GetItemCount() const override;
    void DisplayInfo() const override;
};

#endif
