//
// Created by chen on 19-4-7.
//

#include <iostream>

#include "account.h"

using std::string;
using std::cerr;
using std::endl;

Account::Account(string userName, double money, unsigned int startYear, string password)
: userName(userName), money(money), startYear(startYear), password(password){
//    This is a base class
//    This class will derive two classes called 'VipAccount' and 'NormalAccount'
}

void Account::setPassword(string newPassword) {

    bool result = false;

    while (!result) {
        result = this->_setPassword(newPassword);

        if (result) {
            cerr << "You have already changed the password!" << endl;
            break;
        }
        else {
            cerr << "The password is not in use!" << endl;
            continue;
        }
    }

}

bool judge(string password) {
    std::size_t len = password.length();
    if (len != 6)
        return false;
    else {
        for (char x : password) {
            if (x > '9' || x < '0')
                return false;
        }

        return true;
    }
}

bool Account::_setPassword(std::string newPassword) {
    bool result = judge(newPassword);

    if (newPassword == this->password)
        result = false;

    if (result) {
        this->password = newPassword;
        return true;
    }
    else
        return false;
}
