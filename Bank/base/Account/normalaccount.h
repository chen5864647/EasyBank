//
// Created by chen on 19-4-7.
//

#ifndef BANK_NORMALACCOUNT_H
#define BANK_NORMALACCOUNT_H

#include <list>

#include "account.h"

class NormalAccount;

void saver(const NormalAccount &normalacc);

class NormalAccount : public Account {
    friend void saver(const NormalAccount &normalacc);

public:
    NormalAccount(std::string userName, double money, unsigned int startYear, std::string password = "888888");

    void getAllMoney() override ;

    ~NormalAccount() override ;

    void setPassword(std::string newPassword);

    std::string getName() const override ;

    static std::list<std::string> NormalUserNames;

    static bool judgeExist(std::string tempUserName);

private:
    bool _setPassword(std::string newPassword);

};

#endif //BANK_NORMALACCOUNT_H
