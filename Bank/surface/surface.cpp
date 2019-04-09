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

inline
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
    cout << "||" << endl;

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
    cout << "||" << endl;

    cout << "If you wanna get into the bank manager?" << endl;
    cout << "yes(y) or no(n)?" << endl;

    string choice;
    bool flag;
    while (true) {
        cin >> choice;

        if (choice == "yes" || choice == "y") {
            flag = true;
            break;
        }
        else if (choice == "no" || choice == "n") {
            flag = false;
            break;
        }
        else {
            cout << "You only have two choices!" << endl;
            cout << "Please put down yes or no..." << endl;
            continue;
        }
    }

    if (flag)
        this->work();
    else
        this->quit();

}

inline
void Surface::setHeight(unsigned int newHeight) {
    if (this->_setHeight(newHeight))
        this->height = newHeight;
}

inline
void Surface::setWidth(unsigned int newWidth) {
    if (this->_setWidth(newWidth))
        this->width = newWidth;
}

inline
bool Surface::_setHeight(unsigned int newHeight) {
    if (newHeight > 800 || newHeight < 200)
        return false;
    else
        return true;
}

inline
bool Surface::_setWidth(unsigned int newWidth) {
    if (newWidth > 1500 || newWidth < 400)
        return false;
    else
        return true;
}

inline
void Surface::clear() {
    system("clear");
}

void Surface::work() {

    this->clear();
    this->drawPainting();

    cout << "take your choice!" << endl;
    unsigned short choice;
    cin >> choice;

    switch (choice) {
        case 1:
            this->clear();
            this->createVipAccount();
            break;
        case 2:
            this->clear();
            this->createVipAccount();
            break;
        case 3:
            this->clear();
            this->loginAccount();
            break;
        case 4:
            this->clear();
            this->deleteVipAccount();
            break;
        case 5:
            this->clear();
            this->deleteNormalAccount();
            break;
        case 6:
            this->clear();
            this->quit();
            break;
        default:
            this->clear();
            cerr << "You should give the correct choice!" << endl;
            this->work();
    }

}

void Surface::drawPainting() {
    cout << "||";
    for (int i = 1; i < this->width / 20; ++i)
        cout << "-";
    cout << "||" << endl;

    int count = 0;
    for (int i = 1; i <= this->height / 20; ++i) {
        if (i == 2)
            cout << "||      1.create a new VIP account       ||";

        if (i == 4)
            cout << "||    2.create a new normal account      ||";

        if (i == 6)
            cout << "||       3.login in your account         ||";

        if (i == 8)
            cout << "||        4.delete VIP account           ||";

        if (i == 10)
            cout << "||       5.delete Normal account         ||";

        if (i == 12)
            cout << "||                6.quit                 ||";

        if (i != 2 && i != 4 && i != 6 && i != 8 && i != 10 && i != 12)
            cout << "||                                       ||";

        cout << endl;
    }

    cout << "||";
    for (int i = 1; i < this->width / 20; ++i)
        cout << "-";
    cout << "||" << endl;

}

void Surface::quit() {
    this->clear();

    cout << "||";
    for (int i = 1; i < this->width / 20; ++i)
        cout << "-";
    cout << "||" << endl;

    int count = 0;
    for (int i = 1; i <= this->height / 20; ++i) {
        if (i == 3)
            cout << "||  Thanks for using this bank manager!  ||";

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
    cout << "||" << endl;
}

void Surface::createNormalAccount() {

    cout << "||---------------------------------------||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||     You should give some info         ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           1. userName                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||             2. money                  ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           3. startYear                ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           4. password                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||---------------------------------------||" << endl;

    string userName;

    bool different = true;
    do {
        if (!different)
            cout << "You must give a different userName!" << endl;
        cout << "Give your userName:" << endl;
        cin >> userName;
        different = NormalAccount::judgeExist(userName);
    } while (!different);
    //    judge the userName is different

    cout << "Give your money:" << endl;
    double money;
    cin >> money;

    unsigned int startYear;
    bool correctYear = true;
    do {
        if (!correctYear)
            cout << "You must give a number(<2019)" << endl;
        cout << "Give your startYear:" << endl;
        cin >> startYear;
        correctYear = startYear <= 2019;
    } while (!correctYear);

    bool correctPassword = true;
    string password;
    do {
        if (!correctPassword)
            cout << "You must give a correct password!" << endl;
        cout << "Give your password:" << endl;
        cin >> password;
        correctPassword = judge(password);
    } while (!correctPassword);

    this->clear();

    NormalAccount normalAcc(userName, money, startYear, password);
    saver(normalAcc);
}

void Surface::createVipAccount() {

    cout << "||---------------------------------------||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||     You should give some info         ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           1. userName                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||             2. money                  ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           3. startYear                ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           4. VIPnumber                ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           5. password                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||---------------------------------------||" << endl;

    bool different = true;
    string userName;
    do {
        if (!different)
            cout << "You must give a different userName!" << endl;
        cout << "Give your userName:" << endl;
        cin >> userName;
        different = VipAccount::judgeExist(userName);
    } while (!different);
    //    judge the userName is different

    cout << "Give your money:" << endl;
    double money;
    cin >> money;

    unsigned int startYear;
    bool correctYear = true;
    do {
        if (!correctYear)
            cout << "You must give a number(<2019)" << endl;
        cout << "Give your startYear:" << endl;
        cin >> startYear;
        correctYear = startYear <= 2019;
    } while (!correctYear);

    cout << "Give your VIPnumber:" << endl;
    string VIPnumber;
    cin >> VIPnumber;

    bool correctPassword = true;
    string password;
    do {
        if (!correctPassword)
            cout << "You must give a correct password!" << endl;
        cout << "Give your password:" << endl;
        cin >> password;
        correctPassword = judge(password);
    } while (!correctPassword);

    this->clear();

    VipAccount vipAcc(userName, money, startYear, VIPnumber, password);
    saver(vipAcc);
}

void Surface::loginAccount(){

    cout << "||---------------------------------------||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||     You should give some info         ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           1. userName                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           2. password                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||---------------------------------------||" << endl;

    string userName, password;
    cout << "You should give the username: " << endl;
    cin >> userName;

    bool correctPassword = true;
    do {
        if (!correctPassword)
            cerr << "You should give the correct password!" << endl;

        cout << "you should give the password: " << endl;
        cin >> password;
        correctPassword = judge(password);
    } while (!correctPassword);

    bool result;
    result = loader(userName, password);

    if (!result) {
        cout << "The account doesn't exist!" << endl;
        return ;
    }

}

void Surface::deleteVipAccount() {
    cout << "||---------------------------------------||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||     You should give some info         ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           1. userName                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           2. password                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||---------------------------------------||" << endl;

    string userName, password;
    cout << "You should give the username: " << endl;
    cin >> userName;

    bool correctPassword = true;
    do {
        if (!correctPassword)
            cerr << "You should give the correct password!" << endl;

        cout << "you should give the password: " << endl;
        cin >> password;
        correctPassword = judge(password);
    } while (!correctPassword);

    bool result;
    result = loader(userName, password);

    if (!result) {
        cout << "The account doesn't exist!" << endl;
        return ;
    }

}

void Surface::deleteNormalAccount() {
    cout << "||---------------------------------------||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||     You should give some info         ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           1. userName                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||           2. password                 ||" << endl;
    cout << "||                                       ||" << endl;
    cout << "||---------------------------------------||" << endl;

    string userName, password;
    cout << "You should give the username: " << endl;
    cin >> userName;

    bool correctPassword = true;
    do {
        if (!correctPassword)
            cerr << "You should give the correct password!" << endl;

        cout << "you should give the password: " << endl;
        cin >> password;
        correctPassword = judge(password);
    } while (!correctPassword);

    bool result;
    result = loader(userName, password);

    if (!result) {
        cout << "The account doesn't exist!" << endl;
        return ;
    }

}
