#pragma once
#include <iostream>
#include "Status.h"
#include "Enemy.h"
using namespace std;

class Hero {
public:
    //�X�e�[�^�X�ݒ�
    Hero(const char* pname, int HP, int power) {
        Status cstatus(pname, HP, power);
        status = cstatus;
        herbNum = 3;
    }
    //�U��
    void Attack(Enemy& enemy) {
        enemy.get_status()->set_HP(-1 * status.get_power());
    }
    //�f�o�b�O�p
    void ShowStatus() {
        status.Show();
        cout << "�򑐁@ : " << herbNum << " ��" << endl;
    }
    Status* get_status() {
        Status* pstatus = &status;
        return pstatus;
    }
    bool AttackJudge() {
        if (rand() % 10 == 1) return false;
        return true;
    }

private:
    Status status;
    int herbNum;
};