// Employee.h

#pragma once

#include "Users.h"

enum JobRole {
    Manager,
    Receptionist,
    Chef,
};

class Employee : Users {
private:
    size_t fID;
    JobRole fRole;

public:
    Employee(int aID) noexcept;

    size_t ID() const noexcept { return fID; };
    JobRole Role() const noexcept { return fRole; };

    void MakeReservation(size_t aSize, std::string date) noexcept;
    void EditReservation() noexcept;
    void CancelReservation() noexcept;

    void TakeOrder() noexcept;
    void GenerateInvoice() noexcept;
};

