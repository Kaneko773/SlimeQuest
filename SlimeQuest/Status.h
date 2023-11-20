#pragma once
#include <iostream>
using namespace std;

class Status {
public:
    Status() {
        _name = NULL;
        _HP = 0;
        _MAX_HP = 0;
        _power = 0;
    }
    Status(const char* name, int HP, int power) {
        _name = name;
        _HP = HP;
        _MAX_HP = _HP;
        _power = power;
    }
    void operator=(const Status& status) {
        _name = status._name;
        _HP = status._HP;
        _MAX_HP = status._MAX_HP;
        _power = status._power;
    }
    void set_HP(int value) {
        _HP += value;
        //もし回復で最大HPを越えたとき
        if (_HP > _MAX_HP) {
            //差分を引く
            _HP -= _HP - _MAX_HP;
        }
    }
    int get_power() const {
        return _power;
    }
    //デバッグ用
    void Show() {
        cout << _name << endl;
        cout << "HP     : " << _HP << endl;
        cout << "攻撃力 : " << _power << endl;
    }

private:
    const char* _name;
    int _HP;
    int _MAX_HP;
    int _power;
};