#pragma once
#include <iostream>
#include "User.h"

class Customer : public User
{
public:
	void displayRole() override
	{
		std::cout << "User is: Customer" << std::endl;
	}
};