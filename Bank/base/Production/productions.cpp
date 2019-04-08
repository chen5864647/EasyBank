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

void ProductionA::addMoney(double newMoney) {
    this->money += newMoney;
}

void ProductionA::subMoney(double someMoney) {
    if (this->money >= someMoney)
        this->money -= someMoney;
    else
        cerr << "You don't have so much money!" << endl;

}

ProductionB::ProductionB(string productName, double money, unsigned int startYear, unsigned int nowYear)
: Product(productName, money, startYear, nowYear), profit(0), percent(0.04662) {

    this->work();

}

void ProductionB::work() {
    unsigned int years = this->nowYear - this->startYear;
//    this->profit = this->money * years * percent;

    this->profit = this->money + this->profit;

    for (int i = 0; i < years; ++i)
        this->profit = this->profit * (1 + percent);

    this->profit = this->profit - this->money;

}

ProductionB::~ProductionB() {
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

double ProductionB::getProfitByYear(unsigned short year) {

    unsigned int years = this->nowYear - this->startYear + year;
    double neckProfit = 0;

    neckProfit = this->money;

    for (int i = 0; i < years; ++i)
        neckProfit = neckProfit * (1 + percent);

    neckProfit = neckProfit - this->money;

    return neckProfit;

}

double ProductionB::getAllMoney() const {
//    unsigned int years = this->nowYear - this->startYear;
    return this->profit + this->money;
}

void ProductionB::addMoney(double newMoney) {
    this->money += newMoney;
}

void ProductionB::subMoney(double someMoney) {
    if (this->money >= someMoney)
        this->money -= someMoney;
    else
        cerr << "You don't have so much money!" << endl;

}

ProductionC::ProductionC(string productName, double money, unsigned int startYear, unsigned int nowYear)
: Product(productName, money, startYear, nowYear), profit(0), percent(0.07662) {

    this->work();

}

void ProductionC::work() {
    unsigned int years = this->nowYear - this->startYear;
//    this->profit = this->money * years * percent;

    this->profit = this->money + this->profit;
    if (years > 10)
        years = 10;

    for (int i = 0; i < years; ++i)
        this->profit = this->profit * (1 + percent);

    this->profit = this->profit - this->money;
    if (this->profit > 1000000)
        this->profit = 1000000;

}

ProductionC::~ProductionC() {
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

double ProductionC::getProfitByYear(unsigned short year) {

    unsigned int years = this->nowYear - this->startYear + year;
    if (years > 10)
        years = 10;

    double neckProfit = 0;

    neckProfit = this->money;

    for (int i = 0; i < years; ++i)
        neckProfit = neckProfit * (1 + percent);

    neckProfit = neckProfit - this->money;
    if (neckProfit > 1000000)
        neckProfit = 1000000;

    return neckProfit;

}

double ProductionC::getAllMoney() const {
//    unsigned int years = this->nowYear - this->startYear;
    return this->profit + this->money;
}

void ProductionC::addMoney(double newMoney) {
    this->money += newMoney;
}

void ProductionC::subMoney(double someMoney) {
    if (this->money >= someMoney)
        this->money -= someMoney;
    else
        cerr << "You don't have so much money!" << endl;

}

