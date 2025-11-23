#pragma once

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "dummy_bank_api.hpp"

using namespace std;

class ATMController {
public:
    ATMController();
    ~ATMController() = default;

    bool checkValidInput(const string& str);
    bool verifyCardInfo(const string& cardNum, const string& pinNum);
    int checkBalance();
    void depositMoney(int money);
    void withdrawMoney(int money);

private:
    string cardNum_ = "";
    string pinNum_ = "";

    DummyBankAPI bankAPI;


};