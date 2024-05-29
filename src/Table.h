
#pragma once

#include <iostream>
#include <string>

class Table {
private:
    int tableNumber;
    int size;
    std::string status;

public:
    Table(int number, int size) : tableNumber(number), size(size), status("free") {}

    int getTableNumber() const { return tableNumber; }
    int getSize() const { return size; }
    std::string getStatus() const { return status; }

    void changeStatus(const std::string& newStatus) {
        status = newStatus;
    }
};
