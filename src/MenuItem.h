
#pragma once
#include <string>

class MenuItem {
private:
    std::string name;
    double price;
    bool available;

public:
    MenuItem(const std::string& name, double price, bool available = true)
        : name(name), price(price), available(available) {}

    std::string getName() const { return name; }
    double getPrice() const { return price; }
    bool isAvailable() const { return available; }

    void setAvailability(bool availability) {
        available = availability;
    }
};
