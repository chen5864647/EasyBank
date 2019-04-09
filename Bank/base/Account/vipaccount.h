//
// Created by chen on 19-4-7.
//

#ifndef BANK_VIPACCOUNT_H
#define BANK_VIPACCOUNT_H

#include <memory>
#include <list>
#include <map>

#include "account.h"

enum Production {
    ProdA = 1,
    ProdB = 2,
    ProdC = 3
};

class VipAccount;

void saver(const VipAccount &vipacc);

class VipAccount : public Account {
    friend void saver(const VipAccount &vipacc);

public:

    VipAccount(std::string userName, double money, unsigned int startYear,
               std::string vipNumber, std::string password = "888888");

    void getAllMoney() override ;

    ~VipAccount() override ;

    void setPassword(std::string newPassword);

    void setVipNumber(std::string newVipNumber);

    void addProduction(std::string productionName, double money, Production productionClass);

    void addProductionA(std::string productionName, double money);
    void addProductionB(std::string productionName, double money);
    void addProductionC(std::string productionName, double money);


    void getProductionByName(std::string productionName);
    void getProductionByClass(Production productionClass);
    void getAllProduction();

    void deleteProductionByName(std::string productionName);
    void deleteProductionByClass(Production productionClass);
    void deleteAllProduction();

    std::string getName() const override ;

    static std::list<std::string> VipUserNames;

    static bool judgeExist(std::string tempUserName);

private:
    std::string vipNumber;

    std::unique_ptr<std::map<std::string, ProductionA>> ProductionAs;
    std::unique_ptr<std::map<std::string, ProductionB>> ProductionBs;
    std::unique_ptr<std::map<std::string, ProductionC>> ProductionCs;

    bool _setPassword(std::string newPassword);

};


#endif //BANK_VIPACCOUNT_H
