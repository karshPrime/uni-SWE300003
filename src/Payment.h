#include "PaymentMethod.h"
#include "Customer.h"

class Payment 
{
private:
    PaymentMethod* paymentMethod;
    Customer* customer;

public:
    Payment(PaymentMethod* method, Customer* cust) : paymentMethod(method), customer(cust) 
    {

    }
    void setPaymentMethod(PaymentMethod* method)
    {
        paymentMethod = method;
    }

    void setCustomer(Customer* cust)
    {
        customer = cust;
    }


    void make_Payment(double amount)
    {
        if (paymentMethod && customer) 
        {
            paymentMethod->pay(amount);
            std::cout << "Payment completed." << std::endl; 
        }
    }
};
