#ifndef USER_H
#define USER_H

#include <iostream>

class User {
private:
    int hp;       // 사용자 HP
    int itemCnt;  // 먹은 아이템 수

public:
    User();                       // 생성자
    void DecreaseHP(int dec_hp);  // HP 감소
    void IncreaseHP(int inc_hp);  // HP 증가
    void IncreaseItemCount();     // 아이템 횟수 증가
    int GetHP() const;            // 현재 HP 반환
    int GetItemCount() const;     // 아이템 횟수 반환

    // 출력 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif
