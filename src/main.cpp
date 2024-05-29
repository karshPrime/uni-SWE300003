
#include "Prompts.h"
#include "Customer.h"
#include "Employee.h"

void home_menu();
void customer_menu();
void employee_menu();
void customer_loggedIn();

int main()
{
    char buffer = '\n';         // input buffer
    char userOptions[4] = {0};  // initialise with zero

    void(*menu)() = home_menu;  // default menu

    while (buffer != 'x') {
        std::cout << std::endl;
        menu();
        std::cout << "[?] for help $ ";
        std::cin >> buffer;

        if (buffer == 'h') {
            menu = home_menu;
            std::strcpy(userOptions, "h");
            continue;
        }

        // employee
        if (userOptions[0] == '1') {
            // Placeholder for employee menu handling logic
        }

        // customer
        else if (userOptions[0] == '2') {
            Customer customer;

            // new user
            if (userOptions[1] == '1') {
                customer = Customer();
                menu = customer_loggedIn;
            }

            // to modify existing request
            else if (userOptions[1] == '2') {
                std::string lInputBuffer;
                size_t lID = -1;

                while (lInputBuffer != "x") {
                    std::cout << "Enter your ID : ";
                    std::cin >> lInputBuffer;
                    try {
                        lID = std::stoull(lInputBuffer);
                        buffer = 'x';
                        break;
                    } 
                    catch (...) {
                        std::cout << "Invalid ID. Try again\n";
                    }
                }

                // now look for user with this ID
                customer = Customer(lID); 
                menu = customer_loggedIn;
            }

            else {
                userOptions[1] = buffer; // Store buffer in userOptions[1]
            }
        }

        else {
            userOptions[0] = buffer; // Store buffer in userOptions[0]

            if (buffer == '1')
                menu = customer_menu; // Switch to customer menu

            else if (buffer == '2')
                menu = employee_menu; // Switch to employee menu

            else if (buffer == 'x')
                std::cout << "goodbye\n"; // Exit message

            else
                std::cout << "invalid input\n"; // Invalid input message
        }
    }

    return 0;
}

