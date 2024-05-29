// Customer.h

#pragma once

#include "Users.h"
#include "Payment.h"
#include "Record.h"

class Customer : Users {
private:
    size_t fID;
    size_t fSeats;
    size_t fPhone;
    std::string fName;
    std::string fEmail;
    Record fRecord;

public:
    Customer() noexcept;            // new account
    Customer(size_t aID) noexcept;  // login into existing

    size_t ID() const noexcept { return fID; };
    size_t Seats() const noexcept { return fSeats; };
    size_t Phone() const noexcept { return fPhone; };
    std::string Name() const noexcept { return fName; };
    std::string Email() const noexcept { return fEmail; };

    void AddPayment() noexcept;
    void MakePayment() noexcept;

    void MakeReservation() noexcept;
    void EditReservation() noexcept;
    void CancelReservation() noexcept;
};

