#pragma once
#include <iostream>
#include "PaymentMethod.h"

class Cash : public PaymentMethod 
{
public:
    void pay(double amount) override 
	{
        std::cout << "Cash Payment: $" << amount << std::endl;
    }
};