#include <iostream>
#include <vector>
#include "Payment.h"
#include "InPersonCard.h"
#include "Cash.h"
#include "OnlinePayment.h"
#include "User.h"
#include "CreateUserFactory.h"
#include "Kitchen.h"
#include "Customer.h"
#include "Reservation.h"
#include "Table.h"
#include "MenuItem.h"
#include "Order.h"
#include "Report.h"
#include "Database.h"

// Function declarations
void displayMainMenu();
void handleEmployeeOperations();
void handleCustomerOperations();
void makeReservation(Customer* customer);
void viewReservations();
void manageReservations();

int main() {
    bool running = true;

    while (running) {
        displayMainMenu();

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                handleEmployeeOperations();
                break;
            case 2:
                handleCustomerOperations();
                break;
            case 3:
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}

void displayMainMenu() {
    std::cout << "\nWelcome to the Restaurant Management System" << std::endl;
    std::cout << "[1] Continue as Employee" << std::endl;
    std::cout << "[2] Continue as Customer" << std::endl;
    std::cout << "[3] Exit" << std::endl;
    std::cout << ">>> ";
}

void handleEmployeeOperations() {
    User* employeeUser = CreateUserFactory::createUser(EMPLOYEE);
    Employee* employee = static_cast<Employee*>(employeeUser);
    employee->displayRole();

    bool employeeRunning = true;
    while (employeeRunning) {
        std::cout << "\nEmployee Menu:" << std::endl;
        std::cout << "[1] View Reservations" << std::endl;
        std::cout << "[2] Manage Reservations" << std::endl;
        std::cout << "[3] Exit to Main Menu" << std::endl;
        std::cout << ">>> ";
        
        int employeeChoice;
        std::cin >> employeeChoice;

        switch (employeeChoice) {
            case 1:
                viewReservations();
                break;
            case 2:
                manageReservations();
                break;
            case 3:
                employeeRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    delete employeeUser;
}

void handleCustomerOperations() {
    std::string customerName;
    std::cout << "\nEnter your name: ";
    std::cin >> customerName;

    User* customerUser = CreateUserFactory::createUser(CUSTOMER, customerName);
    Customer* customer = static_cast<Customer*>(customerUser);
    customer->displayRole();

    bool customerRunning = true;
    while (customerRunning) {
        std::cout << "\nCustomer Menu:" << std::endl;
        std::cout << "[1] Make a Payment" << std::endl;
        std::cout << "[2] Make a Reservation" << std::endl;
        std::cout << "[3] Exit to Main Menu" << std::endl;
        std::cout << ">>> ";
        
        int customerChoice;
        std::cin >> customerChoice;

        switch (customerChoice) {
            case 1: {
                PaymentMethod* paymentMethod;
                std::cout << "\nChoose Payment Method:" << std::endl;
                std::cout << "[1] In-Person Card" << std::endl;
                std::cout << "[2] Cash" << std::endl;
                std::cout << "[3] Online Payment" << std::endl;
                std::cout << ">>> ";
                int paymentChoice;
                std::cin >> paymentChoice;

                switch (paymentChoice) {
                    case 1:
                        paymentMethod = new InPersonCard();
                        break;
                    case 2:
                        paymentMethod = new Cash();
                        break;
                    case 3:
                        paymentMethod = new OnlinePayment();
                        break;
                    default:
                        std::cout << "Invalid choice. Defaulting to Cash." << std::endl;
                        paymentMethod = new Cash();
                }

                double amount;
                std::cout << "\nEnter payment amount: ";
                std::cin >> amount;

                Payment payment(paymentMethod, customer);
                payment.make_Payment(amount);

                delete paymentMethod;
                break;
            }
            case 2:
                makeReservation(customer);
                break;
            case 3:
                customerRunning = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    delete customerUser;
}

void makeReservation(Customer* customer) {
    std::vector<Reservation> reservations = Reservation::loadReservations();

    Table table1(1, 4);
    std::string date, time;
    std::cout << "\nEnter reservation date (YYYY-MM-DD): ";
    std::cin >> date;
    std::cout << "Enter reservation time (HH:MM): ";
    std::cin >> time;

    Reservation newReservation("R" + std::to_string(reservations.size() + 1), date, time, customer, &table1);
    
    if (Reservation::isConflicting(newReservation, reservations)) {
        std::cout << "Reservation conflict. Please choose a different time." << std::endl;
    } else {
        Reservation::saveReservation(newReservation);
        std::cout << "Reservation made for " << date << " at " << time << std::endl;
    }
}

void viewReservations() {
    std::vector<Reservation> reservations = Reservation::loadReservations();

    std::cout << "Current Reservations:" << std::endl;
    for (const auto& reservation : reservations) {
        std::cout << "Serial: " << reservation.getSerialNumber()
                  << ", Date: " << reservation.getDate()
                  << ", Time: " << reservation.getTime()
                  << ", Customer: " << reservation.getCustomer()->getName()
                  << ", Table: " << reservation.getTable()->getTableNumber() << std::endl;
    }
}

void manageReservations() {
    // Placeholder for additional management actions
    std::cout << "Reservation management not implemented yet." << std::endl;
}
