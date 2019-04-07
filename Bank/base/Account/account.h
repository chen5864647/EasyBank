//
// Created by chen on 19-4-7.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>

#include "../Production/productions.h"

class Account {
public:
    Account(std::string userName, double money, unsigned int startYear, std::string password = "888888");

    virtual void getAllMoney() = 0;

    virtual ~Account() = default ;

    virtual void setPassword(std::string newPassword);

protected:
    std::string userName;

    double money;

    std::string password;

    bool _setPassword(std::string newPassword);

    unsigned int startYear;

private:

};




#endif //BANK_ACCOUNT_H
