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



    User* employeeUser = CreateUserFactory::createUser(EMPLOYEE);
    Employee* employee = static_cast<Employee*>(employeeUser);

    User* kitchenUser = CreateUserFactory::createUser(KITCHEN);
    Kitchen* kitchen = static_cast<Kitchen*>(kitchenUser);

    User* customerUser1 = CreateUserFactory::createUser(CUSTOMER);
    Customer* customer1 = static_cast<Customer*>(customerUser1);

    User* customerUser2 = CreateUserFactory::createUser(CUSTOMER);
    Customer* customer2 = static_cast<Customer*>(customerUser2);
    


    Payment payment1(&card, customer1);
    payment1.make_Payment(100.0);


    Payment payment2(&online, customer2);
    payment2.make_Payment(200.0);


    payment1.setPaymentMethod(&cash);
    payment1.make_Payment(200.0);

    employee->displayRole();
    kitchen->displayRole();
    customer1->displayRole();




    Table table1(1, 4);
    Reservation reservation("R001", "2023-05-29", "19:00", customer1, &table1);

    MenuItem item1("Pizza", 15.99);
    MenuItem item2("Burger", 9.99);

    Order order("O001", &table1);
    order.addItem(&item1);
    order.addItem(&item2);

    Database db;
    db.addReceipt(&order);

    std::vector<Order*> orders = db.getReceipts();
    Report::generateSalesReport(orders);

    std::vector<Customer*> customers = {customer1};
    Report::generateCustomerActivityReport(customers);

    return 0;
}
