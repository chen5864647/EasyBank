//
// Created by chen on 19-4-9.
//

#ifndef BANK_FUNC_H
#define BANK_FUNC_H

#include <fstream>
#include <iostream>

#include "../base/Account/vipaccount.h"
#include "../base/Account/normalaccount.h"

void saver(const VipAccount &vipacc);

void saver(const NormalAccount &normalacc);

bool loader(std::string userName, std::string password);

void deleteVip(VipAccount &vipAccount);

void deleteNormal(NormalAccount &normalAccount);

void workVipAccount(VipAccount &vipAccount);

void workNormalAccount(NormalAccount &normalAccount);

#endif //BANK_FUNC_H
