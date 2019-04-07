//
// Created by chen on 19-4-7.
//

#include <iostream>

#include "vipaccount.h"

using std::string;
using std::unique_ptr;
using std::map;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

VipAccount::VipAccount(string userName,
        double money,
        unsigned int startYear,
        string vipNumber,
        string password)
: Account(userName, money, startYear, password), vipNumber(vipNumber) {

    cerr << "There is a new account creation!" << endl;
    cerr << "This is a VIP account..." << endl;

    if (!this->ProductionAs.release())
        this->ProductionAs.reset(new std::map<ProductionA, double >);
    else
        this->ProductionAs.reset();

}

void VipAccount::getAllMoney() {

    auto waitProfitAndMoney = *(this->ProductionAs);

    auto item = waitProfitAndMoney.begin();

    double ansMoney = 0;
    ansMoney += this->money;

    while (item != waitProfitAndMoney.end()) {
        ProductionA temp = item->first;
        ansMoney += temp.getAllMoney();
    }

    cout << "You take out all the money!" << endl;
    cout << "In all:" << endl;
    cout << ansMoney << endl;

    this->money = 0;
    this->ProductionAs.release();

}

VipAccount::~VipAccount() {

    bool flag = false;

    if (this->money == 0) {
        auto waitProfitAndMoney = *(this->ProductionAs);
        long productions =  waitProfitAndMoney.size();
        if (productions == 0)
            flag = true;
        else
            flag = false;
    }
    else
        flag = false;

    if (!flag) {
        cerr << "You have money in this account!" << endl;
        cerr << "If you wanna get the money?" << endl;

        string choice;
        cerr << "yes(y) or no(n)..." << endl;

        bool getMoney;

        while (true) {
            cin >> choice;
            if (choice == "yes" || choice == "y") {
                getMoney = true;
                break;
            }
            else if (choice == "no" || choice == "n") {
                getMoney = false;
                break;
            }
            else {
                cerr << "You only have two choices!" << endl;
                cerr << "Please take the choice again!" << endl;
                continue;
            }
        }

        if (getMoney) {
            cout << "You have gotten your money!" << endl;
            this->getAllMoney();
            cout << "You delete your account!" << endl;
        }
    }
    else
        cout << "You delete your account!" << endl;

}

void VipAccount::setPassword(string newPassword) {
    bool flag = this->_setPassword(newPassword);

    if (flag)
        cout << "You have changed your password!" << endl;
    else {
        cout << "You must give a correct password!" << endl;
        cout << "Your password doesn't change!" << endl;
    }
}

bool VipAccount::_setPassword(std::string newPassword) {
    bool flag;

    flag = judge(newPassword);
    if (!flag)
        return false;
    else {
        this->password = newPassword;
        return true;
    }
}
