#include <iostream>

namespace Input
{
	bool tryInput(int& dst)
	{
		std::cin >> dst;

		if (std::cin.eof())
		{
			throw std::runtime_error("EOF");
		}
		if (std::cin.bad())
		{
			throw std::runtime_error("CRITICAL_ERROR");
		}

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			return false;
		}
		return true;
	}

	int input()
	{
		int res;
		while (!tryInput(res));
		return res;
	}
}