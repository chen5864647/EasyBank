cmake_minimum_required(VERSION 3.13)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp base/Account/account.cpp base/Account/account.h base/Production/product.cpp base/Production/product.h base/Production/productions.h base/Production/productions.cpp base/Account/vipaccount.cpp base/Account/vipaccount.h base/Account/normalaccount.cpp base/Account/normalaccount.h)