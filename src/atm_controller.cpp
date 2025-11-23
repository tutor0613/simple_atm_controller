#include "atm_controller.hpp"

ATMController::ATMController() {

}

bool ATMController::getCardInfo(const std::string& cardNum, const std::string& pinNum) {
    bool isValid = verifyCardInfo();
    return isValid;
}

bool ATMController::verifyCardInfo() {
    return true;
}
