#pragma once
#include <iostream>
#include "User.h"
#include "Employee.h"
#include "Kitchen.h"
#include "Customer.h"

enum UserType 
{
    EMPLOYEE,
    CUSTOMER,
    KITCHEN
};

class CreateUserFactory 
{
public:
    static User* createUser(UserType type) 
    {
        if (type == UserType::EMPLOYEE) 
        {
            return new Employee();
        }
        else if (type == UserType::CUSTOMER) 
        {
            return new Customer();
        }
        else if (type == UserType::KITCHEN) 
        {
            return new Kitchen();
        }
        else
        {
            return nullptr;
        }
    }
};
