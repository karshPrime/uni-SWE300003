
#pragma once

#include <vector>
#include "MenuItem.h"
#include "Table.h"

class Order {
private:
    std::string orderId;
    std::vector<MenuItem*> items;
    Table* table;
    std::string status;

public:
    Order(const std::string& id, Table* tbl) : orderId(id), table(tbl), status("pending") {}

    std::string getOrderId() const { return orderId; }
    Table* getTable() const { return table; }
    std::string getStatus() const { return status; }

    void addItem(MenuItem* item) {
        items.push_back(item);
    }

    void removeItem(MenuItem* item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    void updateStatus(const std::string& newStatus) {
        status = newStatus;
    }
};
