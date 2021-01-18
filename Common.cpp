#include "Common.h"

#include <iostream>
#include <iomanip>
#include <Windows.h>


int GetValue()
{
	int value;
	std::cout << " Enter value:" << std::endl;
	std::cin >> value;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Error. You need to enter digits (like 1 or -6).\n";
		return GetValue();
	}

	return value;
}