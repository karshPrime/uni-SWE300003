// OnlinePayment.h

#pragma once

#include <iostream>
#include "PaymentMethod.h"

class OnlinePayment : public PaymentMethod {
public:
    void pay(double amount) override {
        std::cout << "Online Payment: $" << amount << std::endl;
    }
};
