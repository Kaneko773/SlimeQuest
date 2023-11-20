#pragma once
#include <ctime>
#include <cstdlib>
#include "Status.h"
#include "Hero.h"
using namespace std;

class Enemy {
public:
    //�X�e�[�^�X�ݒ�
    Enemy(const char* pname, int HP, int power) {
        Status cstatus(pname, HP, power);
        status = cstatus;
    }
    //�U��
    void Attack(Hero& hero) {
        hero.get_status()->set_HP(-1 * status.get_power());
    }
    //�f�o�b�O�p
    void ShowStatus() {
        status.Show();
    }
    Status* get_status() {
        Status* pstatus = &status;
        return pstatus;
    }
    bool AttackJudge() {
        if (rand() % 10 == 1) return false;
        return true;
    }

protected:
    Status status;
};

class Slime : public Enemy {
    using Enemy::Enemy;
};

class Zombie : public Enemy {
    using Enemy::Enemy;
};