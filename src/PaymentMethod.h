// PaymentMethod.h

#pragma once

#include <iostream>

class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentMethod() {}
};

