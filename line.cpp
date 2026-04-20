#include "line.h"
#include <iostream>
#include <format>

namespace Matr {
	void freeLine(Line& line)
	{

		delete[] line.arr;
		line.arr = nullptr;
		line.len = 0;
	}

	Line createLine(size_t len)
	{
		Line line;
		line.arr = new int[len];
		line.len = len;
		return line;
	}

	void inputLine(Line& line)
	{
		for (int i = 0; i < line.len; i++)
		{
			std::cout << "> " << std::flush;
			line.arr[i] = Input::input();
		}
	}
}
