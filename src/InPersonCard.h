#pragma once

#include <iostream>
#include "PaymentMethod.h"

class InPersonCard : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Card Payment: $" << amount << std::endl;
    }
};