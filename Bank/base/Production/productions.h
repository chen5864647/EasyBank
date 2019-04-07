//
// Created by chen on 19-4-7.
//

#ifndef BANK_PRODUCTIONS_H
#define BANK_PRODUCTIONS_H

#include "product.h"

class Account;

class ProductionA : public Product {

    friend class Account;

public:
    ProductionA(std::string productName, double money, unsigned int startYear, unsigned int nowYear);

    ~ProductionA() override ;

    void work() override ;

    double getProfitByYear(unsigned short year) override ;

    double getAllMoney() const override ;

private:
    double profit;

    double percent;

};

/*

class ProductionB : public Product {
public:
    ProductionB(std::string productName, double money, unsigned int startYear, unsigned int nowYear);

    ~ProductionB();

    void work();

    double getProfitByYear(unsigned short year);

    double getAllMoney() const;

private:
    double profit;

    double percent;

};

class ProductionC : public Product {
public:
    ProductionC(std::string productName, double money, unsigned int startYear, unsigned int nowYear);

    ~ProductionC();

    void work();

    double getProfitByYear(unsigned short year);

    double getAllMoney() const;

private:
    double profit;

    double percent;

};

class ProductionD : public Product {
public:
    ProductionD(std::string productName, double money, unsigned int startYear, unsigned int nowYear);

    ~ProductionD();

    void work();

    double getProfitByYear(unsigned short year);

    double getAllMoney() const;

private:
    double profit;

    double percent;

};

*/
#endif //BANK_PRODUCTIONS_H
