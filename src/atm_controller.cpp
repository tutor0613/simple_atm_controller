#include "atm_controller.hpp"

ATMController::ATMController() {
    bankAPI = DummyBankAPI();
}

bool ATMController::verifyCardInfo(const std::string& cardNum, const std::string& pinNum) {
    bool isValid = bankAPI.verifyCardInfo(cardNum, pinNum);
    if (isValid) {
        cardNum_ = cardNum;
        pinNum_ = pinNum;
    }
    return isValid;
}

int ATMController::checkBalance() {
    int balance = 0;
    if (cardNum_ != "") balance = bankAPI.seeBalance(cardNum_);
    return balance;
}
