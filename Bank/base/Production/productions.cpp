//
// Created by chen on 19-4-7.
//

#include <iostream>

#include "productions.h"

using std::cin;
using std::cerr;
using std::endl;
using std::string;

ProductionA::ProductionA(string productName, double money, unsigned int startYear, unsigned int nowYear)
: Product(productName, money, startYear, nowYear), profit(0), percent(0.04662) {
    this->work();
}

void ProductionA::work() {
    unsigned int years = this->nowYear - this->startYear;
    this->profit = this->money * years * percent;
}

ProductionA::~ProductionA() {
    if (this->money != 0) {
        cerr << "You have money in productionA!" << endl;
        cerr << "If you wanna get the money you have in this production!" << endl;
        cerr << "yes(y) or no(n)!" << endl;

        string choice;
        cin >> choice;

        while (true) {
            if (choice == "yes" || choice == "y") {
                cerr << "You just take the money out!" << endl;

//                do something

                break;
            }
            else if (choice == "no" || choice == "n") {
                cerr << "you take the money away!" << endl;
                break;
            }
            else
                cerr << "you have only two choice!" << endl;
        }
    }
}

double ProductionA::getProfitByYear(unsigned short year) {
    unsigned int years = this->nowYear - this->startYear + year;
    double neckProfit;
    neckProfit = this->money * years * percent;

    return neckProfit;
}

double ProductionA::getAllMoney() const {
//    unsigned int years = this->nowYear - this->startYear;
    return this->profit + this->money;
}