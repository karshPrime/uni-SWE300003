
#include "Customer.h"

void home_menu();
void customer_menu();
void employee_menu();

int main()
{
    char buffer = '\n';         // input buffer
    char userOptions[4];
    size_t instance = 0;

    void(*menu)() = home_menu;  // default menu

    while (buffer != 'x') {
        std::cout << std::endl; menu();
        std::cout << ">>> "; std::cin >> buffer;

        if (buffer == 'h') {
            menu = home_menu;
            userOptions[0] = 'h';
            continue;
        }

        if (userOptions[0] == '1') {
            //
        }

        else if (userOptions[0] == '2') {
            //
        }

        else {
            userOptions[0] = buffer;

            if (buffer == '1')
                menu = customer_menu;

            else if (buffer == '2')
                menu = employee_menu;

            else if (buffer == 'x')
                std::cout << "goodbye\n";
            
            else
                std::cout << "invalid input\n";
        }
    }

    return 0;
}

void home_menu() {
    std::cout << "[1] continue as an employee\n";
    std::cout << "[2] continue as a customer\n";
    std::cout << "[x] exit\n";
}

void customer_menu() {
    std::cout << "[1] new booking\n";
    std::cout << "[2] edit existing booking\n";
    std::cout << "[h] logout to home\n";
    std::cout << "[x] exit\n";
}

void employee_menu() {
    std::cout << "[1] make new reservation\n";
    std::cout << "[2] check existing reservation\n";
    std::cout << "[3] check menu\n";
    std::cout << "[h] logout to home\n";
    std::cout << "[x] exit\n";
}

