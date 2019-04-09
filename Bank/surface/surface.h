//
// Created by chen on 19-4-8.
//

#ifndef BANK_SURFACE_H
#define BANK_SURFACE_H

#include <iostream>
#include <cassert>

#include "../base/Account/vipaccount.h"
#include "../base/Account/normalaccount.h"
#include "func.h"

class Surface {
public:
    Surface();
    Surface(unsigned int width, unsigned int height);

    ~Surface() = default;

    void drawPainting();
    void init();
    void printUsage();

    void setWidth(unsigned int newWidth);
    void setHeight(unsigned int newHeight);

    void clear();

    void work();

    void quit();

    void createVipAccount();

    void createNormalAccount();

    void loginAccount();

    void deleteVipAccount();

    void deleteNormalAccount();

private:
    unsigned int width = 40;
    unsigned int height = 20;

    bool _setWidth(unsigned int newWidth);
    bool _setHeight(unsigned int newHeight);

};

#endif //BANK_SURFACE_H
