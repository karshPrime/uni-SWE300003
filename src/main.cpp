// Main.cpp

#include "Customer.h"
#include "Employee.h"

void customer_test();
void employee_test();

int main()
{
    customer_test();
    employee_test();
}

void customer_test() {
    Customer customer = Customer();

    customer.AddPayment();
    customer.MakePayment();

    customer.MakeReservation(10, "27/12/2024");
    customer.EditReservation();
    customer.CancelReservation();
}

void employee_test() {
    Employee employee = Employee(101);
    // other tests
}

