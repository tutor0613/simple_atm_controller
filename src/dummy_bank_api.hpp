#pragma once

#include <string>
#include <vector>

using namespace std;

class DummyBankAPI {
public:
    DummyBankAPI() {
        cardDB_.push_back(cardInfo{"123456789012", "1234", 3000});
    }

    ~DummyBankAPI() = default;

    bool verifyCardInfo(const string& cardNum, const string& pinNum) {
        bool isValid = false;
        for (cardInfo info : cardDB_) {
            if (info.cardNumber == cardNum) {
                if (info.pinNumber == pinNum) isValid = true;
                break;
            }
        }
        return isValid;
    }

    int seeBalance(const string& cardNum) {
        int balance = 0;
        for (cardInfo info : cardDB_) {
            if (info.cardNumber == cardNum) {
                balance = info.balance;
                break;
            }
        }
        return balance;
    }

    void depositMoney(const string& cardNum, int money) {
        for (int i = 0; i < cardDB_.size(); i++) {
            if (cardDB_[i].cardNumber == cardNum) {
                cardDB_[i].balance += money;
                break;
            }
        }
    }

private:
    struct cardInfo {
        string cardNumber;
        string pinNumber;
        int balance;
    };

    vector<cardInfo> cardDB_{};

};
