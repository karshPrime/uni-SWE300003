// Payment.h

#pragma once

#include "PaymentMethod.h"

class Payment {
private:
    PaymentMethod* paymentMethod;

public:
    Payment(PaymentMethod* method) : paymentMethod(method) {}
    void setPaymentMethod(PaymentMethod* method)
    {
        paymentMethod = method;
    }

    void make_Payment(double amount)
    {
        if (paymentMethod) {
            paymentMethod->pay(amount);
        }
    }
};

