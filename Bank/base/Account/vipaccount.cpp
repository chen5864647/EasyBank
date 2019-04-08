//
// Created by chen on 19-4-7.
//

#include <iostream>
#include <utility>

#include "vipaccount.h"

using std::string;
using std::unique_ptr;
using std::map;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::pair;

VipAccount::VipAccount(string userName,
        double money,
        unsigned int startYear,
        string vipNumber,
        string password)
: Account(userName, money, startYear, password), vipNumber(vipNumber) {

    cerr << "There is a new account creation!" << endl;
    cerr << "This is a VIP account..." << endl;

    if (!this->ProductionAs.release())
        this->ProductionAs.reset(new map<string, ProductionA>);
    else
        this->ProductionAs.reset();

    if (!this->ProductionBs.release())
        this->ProductionBs.reset(new map<string, ProductionB>);
    else
        this->ProductionBs.reset();

    if (!this->ProductionCs.release())
        this->ProductionCs.reset(new map<string, ProductionC>);
    else
        this->ProductionCs.reset();

}

void VipAccount::getAllMoney() {

    auto waitProfitAndMoneyA = *(this->ProductionAs);

    auto itemA = waitProfitAndMoneyA.begin();

    double ansMoneyA = 0;
    ansMoneyA += this->money;

    while (itemA != waitProfitAndMoneyA.end()) {
        ProductionA temp = itemA->second;
        ansMoneyA += temp.getAllMoney();
    }

    auto waitProfitAndMoneyB = *(this->ProductionBs);

    auto itemB = waitProfitAndMoneyB.begin();

    double ansMoneyB = 0;
    ansMoneyB += this->money;

    while (itemB != waitProfitAndMoneyB.end()) {
        ProductionB temp = itemB->second;
        ansMoneyB += temp.getAllMoney();
    }

    auto waitProfitAndMoneyC = *(this->ProductionCs);

    auto itemC = waitProfitAndMoneyC.begin();

    double ansMoneyC = 0;
    ansMoneyC += this->money;

    while (itemC != waitProfitAndMoneyC.end()) {
        ProductionC temp = itemC->second;
        ansMoneyC += temp.getAllMoney();
    }

    auto ansMoney = ansMoneyA + ansMoneyB + ansMoneyC;

    cout << "You take out all the money!" << endl;
    cout << "In all:" << endl;
    cout << ansMoney << endl;

    this->money = 0;
    this->ProductionAs.release();
    this->ProductionBs.release();
    this->ProductionCs.release();

}

VipAccount::~VipAccount() {

    bool flag = false;

    if (this->money == 0) {
        auto waitProfitAndMoneyA = *(this->ProductionAs);
        long productionsA = waitProfitAndMoneyA.size();
        auto waitProfitAndMoneyB = *(this->ProductionBs);
        long productionsB = waitProfitAndMoneyB.size();
        auto waitProfitAndMoneyC = *(this->ProductionCs);
        long productionsC = waitProfitAndMoneyC.size();
        if (productionsA == 0 && productionsB == 0 && productionsC == 0)
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
        }
    }

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

void VipAccount::setVipNumber(string newVipNumber) {

    this->vipNumber = newVipNumber;

}


void VipAccount::addProduction(string productionName, double money, Production productionClass) {

    auto &productionas = *(this->ProductionAs);
    auto &productionbs = *(this->ProductionBs);
    auto &productioncs = *(this->ProductionCs);
    if (productionClass == ProdA) {
        ProductionA productionA(productionName, money, this->startYear, 2019);

        string namer = productionName;
        auto item = productionas.find(namer);
        if (item != productionas.end()) {
            ProductionA &nowPro = item->second;
            nowPro.addMoney(money);
            cout << "You have alreay gotten this productionA!" << endl;
            cout << "Now! You have push more " << money << " money in it!" << endl;
        }
        else {
            productionas.insert(pair<string, ProductionA>(productionName, productionA));
            cout << "You purchase a new productionA now!" << endl;
            cout << "You have " << money << " money in it!" << endl;
        }

    }
    else if (productionClass == ProdB) {
        ProductionB productionB(productionName, money, this->startYear, 2019);

        string namer = productionName;
        auto item = productionbs.find(namer);
        if (item != productionbs.end()) {
            ProductionB &nowPro = item->second;
            nowPro.addMoney(money);
            cout << "You have alreay gotten this productionB!" << endl;
            cout << "Now! You have push more " << money << " money in it!" << endl;
        }
        else {
            productionbs.insert(pair<string, ProductionB>(productionName, productionB));
            cout << "You purchase a new productionB now!" << endl;
            cout << "You have " << money << " money in it!" << endl;
        }

    }
    else if (productionClass == ProdC) {
        ProductionC productionC(productionName, money, this->startYear, 2019);

        string namer = productionName;
        auto item = productioncs.find(namer);
        if (item != productioncs.end()) {
            ProductionC &nowPro = item->second;
            nowPro.addMoney(money);
            cout << "You have alreay gotten this productionC!" << endl;
            cout << "Now! You have push more " << money << " money in it!" << endl;
        }
        else {
            productioncs.insert(pair<string, ProductionC>(productionName, productionC));
            cout << "You purchase a new productionC now!" << endl;
            cout << "You have " << money << " money in it!" << endl;
        }
    }
}

void VipAccount::addProductionA(string productionName, double money) {
    auto &productionas = *(this->ProductionAs);
    ProductionA productionA(productionName, money, this->startYear, 2019);

    string namer = productionName;
    auto item = productionas.find(namer);
    if (item != productionas.end()) {
        ProductionA &nowPro = item->second;
        nowPro.addMoney(money);
        cout << "You have alreay gotten this productionA!" << endl;
        cout << "Now! You have push more " << money << " money in it!" << endl;
    }
    else {
        productionas.insert(pair<string, ProductionA>(productionName, productionA));
        cout << "You purchase a new productionA now!" << endl;
        cout << "You have " << money << " money in it!" << endl;
    }
}

void VipAccount::addProductionB(string productionName, double money) {
    auto &productionbs = *(this->ProductionBs);
    ProductionB productionB(productionName, money, this->startYear, 2019);

    string namer = productionName;
    auto item = productionbs.find(namer);
    if (item != productionbs.end()) {
        ProductionB &nowPro = item->second;
        nowPro.addMoney(money);
        cout << "You have alreay gotten this productionB!" << endl;
        cout << "Now! You have push more " << money << " money in it!" << endl;
    }
    else {
        productionbs.insert(pair<string, ProductionB>(productionName, productionB));
        cout << "You purchase a new productionB now!" << endl;
        cout << "You have " << money << " money in it!" << endl;
    }
}

void VipAccount::addProductionC(string productionName, double money) {
    auto &productioncs = *(this->ProductionCs);
    ProductionC productionC(productionName, money, this->startYear, 2019);

    string namer = productionName;
    auto item = productioncs.find(namer);
    if (item != productioncs.end()) {
        ProductionC &nowPro = item->second;
        nowPro.addMoney(money);
        cout << "You have alreay gotten this productionC!" << endl;
        cout << "Now! You have push more " << money << " money in it!" << endl;
    }
    else {
        productioncs.insert(pair<string, ProductionC>(productionName, productionC));
        cout << "You purchase a new productionC now!" << endl;
        cout << "You have " << money << " money in it!" << endl;
    }
}
