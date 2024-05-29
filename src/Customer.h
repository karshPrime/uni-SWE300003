#pragma once
#include <iostream>
#include <string>
#include "User.h"

class Customer : public User
{
private:
    std::string name;

public:
    Customer(const std::string& name = "Unknown") : name(name) {}

    std::string getName() const {
        return name;
    }

    void displayRole() override {
        std::cout << "User is: Customer" << std::endl;
    }
};
