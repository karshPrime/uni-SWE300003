#pragma once

#include <vector>
#include "Order.h"

class Database {
private:
    std::vector<Order*> receipts;

public:
    void addReceipt(Order* order) {
        receipts.push_back(order);
    }

    const std::vector<Order*>& getReceipts() const {
        return receipts;
    }
};

