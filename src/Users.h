// Users.h

#pragma once

#include <iostream>
#include <cstddef>

#include "Table.h"

class Users {
protected:
    template<typename T>
    T input(std::string prompt);

    Table FindFreeTable(size_t aSeats) noexcept;

public:
    virtual void MakeReservation() noexcept;
    virtual void EditReservation() noexcept;
    virtual void CancelReservation() noexcept;
};
