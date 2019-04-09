//
// Created by chen on 19-4-7.
//

#include <iostream>

#include "normalaccount.h"

using std::string;
using std::cerr;
using std::endl;
using std::cin;
using std::cout;
using std::list;

list<string> NormalAccount::NormalUserNames;

NormalAccount::NormalAccount(std::string userName, double money, unsigned int startYear, std::string password)
: Account(userName, money, startYear, password) {

    cerr << "There is a new account creation!" << endl;
    cerr << "This is a Normal account..." << endl;

}

NormalAccount::~NormalAccount() {

    bool flag;

    if (this->money == 0)
        flag = true;
    else
        flag = false;

    if (!flag) {
        cerr << "You have money in this account!" << endl;
        cerr << "If you wanna get the money!" << endl;

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
        }
    }

    cout << "You delete your account!" << endl;

}

void NormalAccount::setPassword(string newPassword) {
    bool flag = this->_setPassword(newPassword);

    if (flag)
        cout << "You have changed your password!" << endl;
    else {
        cout << "You must give a correct password!" << endl;
        cout << "Your password doesn't change!" << endl;
    }
}

bool NormalAccount::_setPassword(string newPassword) {
    bool flag;

    flag = judge(newPassword);
    if (!flag)
        return false;
    else {
        this->password = newPassword;
        return true;
    }
}

void NormalAccount::getAllMoney() {
    double allMoney = this->money;

    cout << "You take out all the money!" << endl;
    cout << "In all:" << endl;
    cout << allMoney << endl;

    this->money = 0;
}

inline
string NormalAccount::getName() const {
    return this->userName;
}

bool NormalAccount::judgeExist(string tempUserName) {
    auto item = NormalAccount::NormalUserNames.begin();
    while (item != NormalAccount::NormalUserNames.end()) {
        if (*item == tempUserName)
            return false;
        else
            ++item;
    }

    return true;
}
