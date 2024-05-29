
#pragma once

#include <vector>
#include "Order.h"
#include "Customer.h"

class Report {
public:
    static void generateSalesReport(const std::vector<Order*>& orders) {
        // Implement sales report generation
    }

    static void generateCustomerActivityReport(const std::vector<Customer*>& customers) {
        // Implement customer activity report generation
    }
};
