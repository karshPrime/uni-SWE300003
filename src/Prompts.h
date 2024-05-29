// Prompts.h

#pragma once

#include <iostream>
#include <cstring> // for std::strcpy
#include <string>

void home_menu()
{
    std::cout << "[1] continue as an employee\n";
    std::cout << "[2] continue as a customer\n";
    std::cout << "[x] exit\n";
}


// CUSTOMER PROMPTS ===========================================================

void customer_menu()
{
    std::cout << "[1] new booking\n";
    std::cout << "[2] edit existing booking\n";
    std::cout << "[h] logout to home\n";
    std::cout << "[x] exit\n";
}

void customer_loggedIn() {
    std::cout << "[1] check bookings\n";
    std::cout << "[2] make new booking\n";
    std::cout << "[h] logout to home\n";
    std::cout << "[x] exit\n";
}

// EMPLOYER PROMPTS ===========================================================

void employee_menu()
{
    std::cout << "[1] make new reservation\n";
    std::cout << "[2] check existing reservation\n";
    std::cout << "[3] check menu\n";
    std::cout << "[h] logout to home\n";
    std::cout << "[x] exit\n";
}

// void () {
//     std::cout << "[]\n";
//     std::cout << "[h] logout to home\n";
//     std::cout << "[x] exit\n";
// }

