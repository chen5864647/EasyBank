//
// Created by chen on 19-4-9.
//

#include <string>


#include "func.h"

using namespace std;

void saver(const VipAccount &vipacc) {
    string userName = vipacc.getName();
    string location = "../data/VipAccount/";

    string fileName = location + userName;
    fstream outFile(fileName.c_str());
//    if (!outFile.is_open())
    while (!outFile.is_open())
        outFile.open(fileName.c_str(), ofstream::app);

    
}

void saver(const NormalAccount &normalacc) {
    string userName = normalacc.getName();
    string location = "../data/NormalAccount/";

    string fileName = location + userName;
    fstream outFile(fileName.c_str());
//    if (!outFile.is_open())
    while (!outFile.is_open())
        outFile.open(fileName.c_str(), ofstream::app);

}