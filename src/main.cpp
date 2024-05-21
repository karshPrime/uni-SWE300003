#include "Payment.h"
#include "InPersonCard.h"
#include "Cash.h"
#include "OnlinePayment.h"
#include "User.h"
#include "CreateUserFactory.h"
#include "Kitchen.h"
#include "Customer.h"

int main() {
    InPersonCard card;
    Cash cash;
    OnlinePayment online;

    Payment payment(&card);
    payment.make_Payment(100.0);

    payment.setPaymentMethod(&cash);
    payment.make_Payment(200.0);

    payment.setPaymentMethod(&online);
    payment.make_Payment(300.0);

    User* employee = CreateUserFactory::createUser(EMPLOYEE);
    User* customer = CreateUserFactory::createUser(CUSTOMER);
    User* kitchen = CreateUserFactory::createUser(KITCHEN);

    if (employee) {
        employee->displayRole();
    }

    if (customer) {
        customer->displayRole();
    }

    if (kitchen) {
        kitchen->displayRole();
    }

    return 0;
}