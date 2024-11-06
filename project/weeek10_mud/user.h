#ifndef USER_H
#define USER_H

class User {
private:
    int hp;

public:
    User();                        // 생성자
    void DecreaseHP(int dec_hp);   // HP가 감소하는 멤버함수
    void IncreaseHP(int inc_hp);   // HP 증가하는 멤버함수
    int GetHP() const;             // 현재 HP 반환 함수
};

#endif // USER_H