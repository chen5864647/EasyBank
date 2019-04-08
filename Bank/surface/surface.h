//
// Created by chen on 19-4-8.
//

#ifndef BANK_SURFACE_H
#define BANK_SURFACE_H

#include "../base/Account/vipaccount.h"
#include "../base/Account/normalaccount.h"
#include <iostream>
#include <cassert>

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

private:
    unsigned int width;
    unsigned int height;

    bool _setWidth(unsigned int newWidth);
    bool _setHeight(unsigned int newHeight);

};


#endif //BANK_SURFACE_H
