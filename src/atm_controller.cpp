#include "atm_controller.hpp"

ATMController::ATMController() {
    bankAPI = DummyBankAPI();
}

bool ATMController::checkValidInput(const string& str) {
    bool isValid = true;
    for (char c : str) {
        int ascii = static_cast<int>(c);
        if (ascii < 48 || ascii > 57) isValid = false;
    }
    return isValid;
}

bool ATMController::verifyCardInfo(const string& cardNum, const string& pinNum) {
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

void ATMController::depositMoney(int money) {
    if (cardNum_ != "") bankAPI.depositMoney(cardNum_, money);
}
