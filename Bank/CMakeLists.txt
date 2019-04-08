cmake_minimum_required(VERSION 3.13)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

include_directories(base/Account)
include_directories(base/Production)

add_executable(Bank
        base/Account/account.cpp
        base/Account/account.h
        base/Account/normalaccount.cpp
        base/Account/normalaccount.h
        base/Account/vipaccount.cpp
        base/Account/vipaccount.h
        base/Production/product.cpp
        base/Production/product.h
        base/Production/productions.cpp
        base/Production/productions.h
        main.cpp)
