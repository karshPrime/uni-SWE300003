#pragma once

#include <string>
#include <vector>
#include <fstream>
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

    static std::vector<Reservation> loadReservations() {
        std::vector<Reservation> reservations;
        std::ifstream file("reservations.txt");

        if (file.is_open()) {
            std::string serial, date, time, customerName;
            int tableNumber, tableSize;

            while (file >> serial >> date >> time >> customerName >> tableNumber >> tableSize) {
                Customer* customer = new Customer(customerName);
                Table* table = new Table(tableNumber, tableSize);
                reservations.emplace_back(serial, date, time, customer, table);
            }
            file.close();
        }

        return reservations;
    }

    static void saveReservation(const Reservation& reservation) {
        std::ofstream file("reservations.txt", std::ios::app);
        if (file.is_open()) {
            file << reservation.serialNumber << " "
                 << reservation.date << " "
                 << reservation.time << " "
                 << reservation.customer->getName() << " "
                 << reservation.table->getTableNumber() << " "
                 << reservation.table->getSize() << std::endl;
            file.close();
        }
    }

    static bool isConflicting(const Reservation& newReservation, const std::vector<Reservation>& reservations) {
        for (const auto& reservation : reservations) {
            if (reservation.getDate() == newReservation.getDate() && 
                reservation.getTime() == newReservation.getTime()) {
                return true;
            }
        }
        return false;
    }
};
