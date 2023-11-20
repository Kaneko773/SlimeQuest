#pragma once
#include <iostream>
#include "Status.h"
#include "Enemy.h"
using namespace std;

class Hero {
public:
    //ステータス設定
    Hero(const char* pname, int HP, int power) {
        Status cstatus(pname, HP, power);
        status = cstatus;
        herbNum = 3;
    }
    //攻撃
    void Attack(Enemy& enemy) {
        enemy.get_status()->set_HP(-1 * status.get_power());
    }
    //デバッグ用
    void ShowStatus() {
        status.Show();
        cout << "薬草　 : " << herbNum << " 枚" << endl;
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