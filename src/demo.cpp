#include "atm_controller.hpp"

using namespace std;

string cardNum_ = "";
string pinNum_ = "";

enum Menu {BALANCE, DEPOSIT, WITHDRAW, NONE};


bool checkValidInput(const string& str) {
    bool isValid = true;
    for (char c : str) {
        int ascii = static_cast<int>(c);
        if (ascii < 48 || ascii > 57) isValid = false;
    }
    return isValid;
}

bool insertCard() {
    string input;
    cout << "Insert your card. (Replace to get card number.)" << endl;
    cout << "Card number (ex: 12345678) : ";
    cin >> input;
    if (!checkValidInput(input)) {
        cout << "Invalid input. Card number must consist only digit." << endl;
        return false;
    }

    cardNum_ = input;
    input = "";

    cout << "Press PIN number of this account." << endl;
    cout << "PIN number (ex: 1234) : ";
    cin >> input;
    if (!checkValidInput(input)) {
        cout << "Invalid input. PIN number must consist only digit." << endl;
        cardNum_ = "";
        return false;
    }
    pinNum_ = input;

    return true;
}

int main() {
    try {
        ATMController controller{};

        std::string input = "";
        cout << "-------------------------------------------------------------" << endl;
        cout << "  Welcome to Youngpyeong Kim's ATM Controller DEMO program.  " << endl << endl;
        cout << "  Please select what you want :" << endl;
        cout << "    - (1) : See Balance" << endl;
        cout << "    - (2) : Deposit" << endl;
        cout << "    - (3) : Withdraw" << endl;
        cout << "    - (q) : quit" << endl << endl;
        cout << "input ( ex: 1 ) : ";
        cin >> input;
        cout << endl;

        Menu menu = NONE;
        if (input == "1") {
            menu = BALANCE;
            cout << "See Balance menu." << endl;
        }
        else if (input == "2") {
            menu = DEPOSIT;
            cout << "Deposit menu." << endl;
        }
        else if (input == "3") {
            menu = WITHDRAW;
            cout << "Withdraw menu." << endl;
        }
        else if (input == "q") cout << "Quit." << endl;
        else cout << "Wrong input." << endl;

        if (menu != NONE) {
            if (insertCard()) {
                if (!controller.verifyCardInfo(cardNum_, pinNum_)) {
                    cout << "Invalid Card. (Card number and PIN number isn't match.)" << endl;
                    cardNum_ = "";
                    pinNum_ = "";
                }
                else {
                    switch (menu) {
                        case BALANCE:
                            cout << "Your account balance : $" << controller.checkBalance() << "." << endl;
                            break;
                        case DEPOSIT:
                            break;
                        case WITHDRAW:
                            break;
                        default:
                            break;
                    }
                }
            }
        }

        cout << "Program will be terminated." << endl;
    }
    catch (const exception& e) {
        cout << "Except in main : " << e.what() << endl;
    }

    return 0;
}