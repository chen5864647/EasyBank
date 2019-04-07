//
// Created by chen on 19-4-7.
//

#ifndef BANK_PRODUCT_H
#define BANK_PRODUCT_H

#include <string>

class Product {
public:
    Product(std::string productName, double money, unsigned int startYear, unsigned int nowYear);

    virtual void work() = 0;

    virtual ~Product() = default;

    virtual double getProfitByYear(unsigned short year) = 0;

    virtual double getAllMoney() const = 0;

protected:
    std::string productName;
    double money;

    unsigned int startYear;

    unsigned int nowYear;

};


#endif //BANK_PRODUCT_H
