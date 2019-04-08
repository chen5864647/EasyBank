//
// Created by chen on 19-4-8.
//

#include <iostream>
#include <cstdlib>

#include "surface.h"

using namespace std;

Surface::Surface() {
    this->init();

    this->printUsage();
}

Surface::Surface(unsigned int width, unsigned int height)
: width(width), height(height) {
    this->init();

    this->printUsage();

}

void Surface::init() {

    if (this->width < 400 || this->width > 1500)
        this->width = 800;

    if (this->height < 200 || this->height > 800)
        this->height = 300;

}

void Surface::printUsage() {
//    print the usage

    cout << "||";
    for (int i = 1; i < this->width / 20; ++i)
        cout << "-";

    int count = 0;
    for (int i = 1; i <= this->height / 20; ++i) {
        if (i == 3)
            cout << "||       This is a bank manager!         ||";

        if (i == 6)
            cout << "||         Designed by Chen...           ||";

        if (i == 9)
            cout << "||         Github: chen5964647           ||";

        if (i != 3 && i != 6 && i != 9)
            cout << "||                                       ||";

        cout << endl;
    }

    cout << "||";
    for (int i = 1; i < this->width / 20; ++i)
        cout << "-";
    cout << "||";

//    this->work();

}

void Surface::setHeight(unsigned int newHeight) {
    if (this->_setHeight(newHeight))
        this->height = newHeight;
}

void Surface::setWidth(unsigned int newWidth) {
    if (this->_setWidth(newWidth))
        this->width = newWidth;
}

bool Surface::_setHeight(unsigned int newHeight) {
    if (newHeight > 800 || newHeight < 200)
        return false;
    else
        return true;
}

bool Surface::_setWidth(unsigned int newWidth) {
    if (newWidth > 1500 || newWidth < 400)
        return false;
    else
        return true;
}

void Surface::clear() {
    system("clear");
}
