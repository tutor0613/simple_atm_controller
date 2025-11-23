#pragma once

#include <iostream>
#include <string>
#include "dummy_bank_api.hpp"

using namespace std;

class ATMController {
public:
    ATMController();
    ~ATMController() = default;

    bool verifyCardInfo(const std::string& cardNum, const std::string& pinNum);
    int checkBalance();


private:
    string cardNum_ = "";
    string pinNum_ = "";

    DummyBankAPI bankAPI;


};