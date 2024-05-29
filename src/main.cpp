#include "Payment.h"
#include "InPersonCard.h"
#include "Cash.h"
#include "OnlinePayment.h"
#include "User.h"
#include "CreateUserFactory.h"
#include "Kitchen.h"
#include "Customer.h"
#include "Reservation.h"
#include "Table.h"
#include "MenuItem.h"
#include "Order.h"
#include "Report.h"
#include "Database.h"

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

    employee->displayRole();
    customer->displayRole();
    kitchen->displayRole();

    Customer* cust = static_cast<Customer*>(customer);
    Table table1(1, 4);
    Reservation reservation("R001", "2023-05-29", "19:00", cust, &table1);

    MenuItem item1("Pizza", 15.99);
    MenuItem item2("Burger", 9.99);

    Order order("O001", &table1);
    order.addItem(&item1);
    order.addItem(&item2);

    Database db;
    db.addReceipt(&order);

    std::vector<Order*> orders = db.getReceipts();
    Report::generateSalesReport(orders);

    std::vector<Customer*> customers = {cust};
    Report::generateCustomerActivityReport(customers);

    return 0;
}
