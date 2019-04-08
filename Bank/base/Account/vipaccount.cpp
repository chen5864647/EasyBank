//
// Created by chen on 19-4-7.
//

#include <iostream>
#include <utility>
#include <array>
#include <algorithm>

#include "vipaccount.h"

using std::string;
using std::unique_ptr;
using std::map;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::pair;
using std::fill;
using std::array;

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

bool VipAccount::_setPassword(string newPassword) {
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

void VipAccount::getProductionByName(string productionName) {
    auto &productionas = *(this->ProductionAs);
    auto &productionbs = *(this->ProductionBs);
    auto &productioncs = *(this->ProductionCs);

    array<bool, 3> vis;
    fill(vis.begin(), vis.end(), false);

    auto itemA = productionas.find(productionName);
    if (itemA != productionas.end()) {
        double temp_money = 0;
        temp_money = itemA->second.getAllMoney();

        this->money += temp_money;
        productionas.erase(itemA);
        vis[0] = true;
    }

    auto itemB = productionbs.find(productionName);
    if (itemB != productionbs.end()) {
        double temp_money = 0;
        temp_money = itemB->second.getAllMoney();

        this->money += temp_money;
        productionbs.erase(itemB);
        vis[1] = true;
    }

    auto itemC = productioncs.find(productionName);
    if (itemC != productioncs.end()) {
        double temp_money = 0;
        temp_money = itemC->second.getAllMoney();

        this->money += temp_money;
        productioncs.erase(itemC);
        vis[2] = true;
    }

    if (vis[0])
        cout << "You get the productionA!" << endl;
    if (vis[1])
        cout << "You get the productionB!" << endl;
    if (vis[2])
        cout << "You get the productionC!" << endl;

}

void VipAccount::getProductionByClass(Production productionClass) {
    unsigned short count = 0;

    auto &productionas = *(this->ProductionAs);
    auto &productionbs = *(this->ProductionBs);
    auto &productioncs = *(this->ProductionCs);

    double ans_money = 0;

    if (productionClass == ProdA) {
        auto item = productionas.begin();
        while (item != productionas.end())
            ans_money += (item->second).getAllMoney();

        count = productionas.size();

        while (!productionas.empty())
            productionas.clear();

    }
    else if (productionClass == ProdB) {
        auto item = productionbs.begin();
        while (item != productionbs.end())
            ans_money += (item->second).getAllMoney();

        count = productionbs.size();

        while (!productionbs.empty())
            productionbs.clear();
    }
    else if (productionClass == ProdC) {
        auto item = productioncs.begin();
        while (item != productioncs.end())
            ans_money += (item->second).getAllMoney();

        count = productioncs.size();

        while (!productioncs.empty())
            productioncs.clear();
    }

    this->money += ans_money;

    cout << "You have gotten " << count << " productions!" << endl;
    cout << "You get " << ans_money << " money!" << endl;

}

void VipAccount::getAllProduction() {
    unsigned short count = 0;

    auto &productionas = *(this->ProductionAs);
    auto &productionbs = *(this->ProductionBs);
    auto &productioncs = *(this->ProductionCs);

    double ansA = 0, ansB = 0, ansC = 0;

    auto itemA = productionas.begin();
    while (itemA != productionas.end()) {
        auto &temp_productiona = itemA->second;
        ansA += temp_productiona.getAllMoney();
        count++;
    }

    while (!productionas.empty())
        productionas.clear();

    auto itemB = productionbs.begin();
    while (itemB != productionbs.end()) {
        auto &temp_productionb = itemB->second;
        ansB += temp_productionb.getAllMoney();
        count++;
    }

    while (!productionbs.empty())
        productionbs.clear();

    auto itemC = productioncs.begin();
    while (itemC != productioncs.end()) {
        auto &temp_productionc = itemC->second;
        ansC += temp_productionc.getAllMoney();
        count++;
    }

    while (!productioncs.empty())
        productioncs.clear();

    double ans = ansA + ansB + ansC;

    cout << "You have gotten all the production!" << endl;
    cout << "In all : " << count << (count > 1 ? "productions..." : "producion...") << endl;
    cout << "In all : " << ans << " money!" << endl;

}

void VipAccount::deleteProductionByName(string productionName) {

    unsigned short count = 0;

    auto &productionas = *(this->ProductionAs);
    auto &productionbs = *(this->ProductionBs);
    auto &productioncs = *(this->ProductionCs);

    double ansA = 0, ansB = 0, ansC = 0;

    auto itemA = productionas.begin();
    while (itemA != productionas.end()) {
        auto &temp_productiona = itemA->second;
        ansA += temp_productiona.getAllMoney();
        count++;
    }

    while (!productionas.empty())
        productionas.clear();

    auto itemB = productionbs.begin();
    while (itemB != productionbs.end()) {
        auto &temp_productionb = itemB->second;
        ansB += temp_productionb.getAllMoney();
        count++;
    }

    while (!productionbs.empty())
        productionbs.clear();

    auto itemC = productioncs.begin();
    while (itemC != productioncs.end()) {
        auto &temp_productionc = itemC->second;
        ansC += temp_productionc.getAllMoney();
        count++;
    }

    while (!productioncs.empty())
        productioncs.clear();

    double ans = ansA + ansB + ansC;
    this->money += ans;

    cout << "You have gotten all the production!" << endl;
    cout << "In all : " << count << (count > 1 ? "productions..." : "producion...") << endl;
    cout << "In all : " << ans << " money!" << endl;
}

void VipAccount::deleteProductionByClass(Production productionClass) {
    unsigned short count = 0;

    auto &productionas = *(this->ProductionAs);
    auto &productionbs = *(this->ProductionBs);
    auto &productioncs = *(this->ProductionCs);

    double ansA = 0, ansB = 0, ansC = 0;

    if (productionClass == ProdA) {

        auto itemA = productionas.begin();
        while (itemA != productionas.end()) {
            auto &temp_productiona = itemA->second;
            ansA += temp_productiona.getAllMoney();
            count++;
        }

        while (!productionas.empty())
            productionas.clear();

        cout << "You delete all the ProductionA!" << endl;
        cout << "In all : " << count << (count > 1 ? "productions" : "production") << endl;
        cout << "In all : " << ansA << " money!" << endl;

    }
    else if (productionClass == ProdB) {
        auto itemB = productionbs.begin();
        while (itemB != productionbs.end()) {
            auto &temp_productionb = itemB->second;
            ansB += temp_productionb.getAllMoney();
            count++;
        }

        while (!productionbs.empty())
            productionbs.clear();

        cout << "You delete all the ProductionB!" << endl;
        cout << "In all : " << count << (count > 1 ? "productions" : "production") << endl;
        cout << "In all : " << ansB << " money!" << endl;

    }
    else if (productionClass == ProdC) {
        auto itemC = productioncs.begin();
        while (itemC != productioncs.end()) {
            auto &temp_productionc = itemC->second;
            ansC += temp_productionc.getAllMoney();
            count++;
        }

        while (!productioncs.empty())
            productioncs.clear();

        cout << "You delete all the ProductionC!" << endl;
        cout << "In all : " << count << (count > 1 ? "productions" : "production") << endl;
        cout << "In all : " << ansC << " money!" << endl;

    }
}

void VipAccount::deleteAllProduction() {

    unsigned short count = 0;

    auto &productionas = *(this->ProductionAs);
    auto &productionbs = *(this->ProductionBs);
    auto &productioncs = *(this->ProductionCs);

    double ansA = 0, ansB = 0, ansC = 0;

    auto itemA = productionas.begin();
    while (itemA != productionas.end()) {
        auto &temp_productiona = itemA->second;
        ansA += temp_productiona.getAllMoney();
        count++;
    }

    while (!productionas.empty())
        productionas.clear();

    auto itemB = productionbs.begin();
    while (itemB != productionbs.end()) {
        auto &temp_productionb = itemB->second;
        ansB += temp_productionb.getAllMoney();
        count++;
    }

    while (!productionbs.empty())
        productionbs.clear();

    auto itemC = productioncs.begin();
    while (itemC != productioncs.end()) {
        auto &temp_productionc = itemC->second;
        ansC += temp_productionc.getAllMoney();
        count++;
    }

    while (!productioncs.empty())
        productioncs.clear();

    double ans = ansA + ansB + ansC;

    cout << "You have delete all the production!" << endl;
    cout << "In all : " << count << (count > 1 ? "productions..." : "producion...") << endl;
    cout << "In all : " << ans << " money!" << endl;

}
