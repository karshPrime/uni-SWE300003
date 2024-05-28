
#include <iostream>

class Users {
protected:
    template<typename T>
    T input(std::string prompt);

public:
    virtual void MakeReservation() noexcept;
    virtual void EditReservation() noexcept;
    virtual void CancelReservation() noexcept;

};

