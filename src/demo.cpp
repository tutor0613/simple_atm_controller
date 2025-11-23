#include "atm_controller.hpp"

using namespace std;

enum Menu {BALANCE, DEPOSIT, WITHDRAW, NONE};

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
        if (input == "1") menu = BALANCE;
        else if (input == "2") menu = DEPOSIT;
        else if (input == "3") menu = WITHDRAW;
        else if (input == "q") cout << "Quit." << endl;
        else cout << "Wrong input." << endl;

        switch (menu) {
            case BALANCE:
                cout << "See Balance menu." << endl;
                break;
            case DEPOSIT:
                cout << "Deposit menu." << endl;
                break;
            case WITHDRAW:
                cout << "Withdraw menu." << endl;
                break;
            default:
                cout << "Program will be terminated." << endl;
                break;
        }
    }
    catch (const exception& e) {
        cout << "Except in main : " << e.what() << endl;
    }

    return 0;
}