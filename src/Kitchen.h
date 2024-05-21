#pragma once
#include <iostream>
#include "User.h"

class Kitchen : public User
{
public:
	void displayRole() override
	{
		std::cout << "User is: Kitchen" << std::endl;
	}
};