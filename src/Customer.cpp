// Customer.cpp

#include "Customer.h"

Customer::Customer() noexcept {
    std::cout << "Create New Account\n";
    std::string fName = input<std::string>("Name");
    size_t fSeats = input<size_t>("Seats");
    size_t fPhone = input<size_t>("Phone");

    // generate ID
    // create file
}

Customer::Customer(size_t aID) noexcept :
    fID(aID)
{
    // get information from saved file for this id
}

void Customer::AddPayment() noexcept
{}

void Customer::MakePayment() noexcept
{}

void Customer::MakeReservation() noexcept
{}

void Customer::CancelReservation() noexcept
{}

void Customer::EditReservation() noexcept
{}

