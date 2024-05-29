
#pragma once

#include <string>
#include "Customer.h"
#include "Table.h"

class Reservation {
private:
    std::string serialNumber;
    std::string date;
    std::string time;
    Customer* customer;
    Table* table;

public:
    Reservation(const std::string& serial, const std::string& date, const std::string& time, Customer* cust, Table* tbl)
        : serialNumber(serial), date(date), time(time), customer(cust), table(tbl) {}

    std::string getSerialNumber() const { return serialNumber; }
    std::string getDate() const { return date; }
    std::string getTime() const { return time; }
    Customer* getCustomer() const { return customer; }
    Table* getTable() const { return table; }

    void update(const std::string& newDate, const std::string& newTime) {
        date = newDate;
        time = newTime;
    }

    void cancel() {
        // Implement cancellation logic
    }
};
