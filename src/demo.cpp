#include "atm_controller.hpp"

int main() {
    try {
        std::cout << "demo start" << std::endl;

        ATMController controller{};
        std::cout << "controller connected : " << static_cast<int>(controller.getCardInfo("123","456")) << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Except in main : " << e.what() << std::endl;
    }

    return 0;
}