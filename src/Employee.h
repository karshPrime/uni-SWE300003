#pragma once
#include <iostream>
#include "User.h"

class Employee : public User
{
public:
	void displayRole() override
	{
		std::cout << "User is: Employee" << std::endl;
	}
};