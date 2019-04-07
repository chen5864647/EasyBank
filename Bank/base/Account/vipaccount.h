//
// Created by chen on 19-4-7.
//

#ifndef BANK_VIPACCOUNT_H
#define BANK_VIPACCOUNT_H

#include <memory>
#include <map>

#include "account.h"

class VipAccount : public Account {
public:

    VipAccount(std::string userName, double money, unsigned int startYear,
               std::string vipNumber, std::string password = "888888");

    void getAllMoney() override ;

    ~VipAccount() override ;

    void setPassword(std::string newPassword);

private:
    std::string vipNumber;

    std::unique_ptr<std::map<ProductionA, double>> ProductionAs;
};


#endif //BANK_VIPACCOUNT_H
