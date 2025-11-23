#pragma once

#include <iostream>
#include <string>

class ATMController {
public:
    ATMController();
    ~ATMController() = default;

    bool getCardInfo(const std::string& cardNum, const std::string& pinNum);


private:
    bool verifyCardInfo();


};