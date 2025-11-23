#include "atm_controller.hpp"

using namespace std;

string cardNum_ = "";
string pinNum_ = "";

enum Menu {BALANCE, DEPOSIT, WITHDRAW, NONE};

void sleep(int ms) {  // [ms]
    this_thread::sleep_for(chrono::milliseconds(ms));
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
            string input;
            cout << "Insert your card. (Replace to get card number.)" << endl;
            cout << "Card number (ex: 12345678) : ";
            cin >> input;
            if (!controller.checkValidInput(input)) {
                cout << "Invalid input. Card number must consist only digit." << endl;
                throw runtime_error("Invalid input.");
            }
            cardNum_ = input;
            input = "";

            cout << "Press PIN number of this account." << endl;
            cout << "PIN number (ex: 1234) : ";
            cin >> input;
            if (!controller.checkValidInput(input)) {
                cout << "Invalid input. PIN number must consist only digit." << endl;
                throw runtime_error("Invalid input.");
            }
            pinNum_ = input;

            if (!controller.verifyCardInfo(cardNum_, pinNum_)) {
                cout << "Invalid Card. (Card number and PIN number isn't match.)" << endl;
                throw runtime_error("Invalid card information.");
            }

            cout << "Card identified. Please wait..." << endl << endl;
            sleep(1000);

            switch (menu) {
                case BALANCE:
                    cout << "Your account balance : $" << controller.checkBalance() << "." << endl;
                    break;
                case DEPOSIT: {
                    string input;
                    cout << "Put in cash into cash bin. (Replace to get number [$].)" << endl;
                    cout << "Cash to deposit (ex: 500) : ";
                    cin >> input;
                    if (!controller.checkValidInput(input)) {
                        cout << "Invalid input. Cash must consist only digit." << endl;
                        throw runtime_error("Invalid input.");
                    }
                    controller.depositMoney(stoi(input));
                    cout << "Deposit $" << input << " to account. Please wait..." << endl;
                    sleep(1000);
                    cout << "Deposit succeeded. Your account balance : $" << controller.checkBalance() << "." << endl;
                    break;
                }
                case WITHDRAW:
                    break;
                default:
                    break;
            }
        }
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    cout << endl << "Program will be terminated." << endl;

    return 0;
}