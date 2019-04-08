//
// Created by chen on 19-4-7.
//

#ifndef BANK_NORMALACCOUNT_H
#define BANK_NORMALACCOUNT_H

#include "account.h"

class NormalAccount : public Account {
public:
    NormalAccount(std::string userName, double money, unsigned int startYear, std::string password = "888888");

    void getAllMoney() override ;

    ~NormalAccount() override ;

    void setPassword(std::string newPassword);

private:
    bool _setPassword(std::string newPassword);

};

#endif //BANK_NORMALACCOUNT_H
