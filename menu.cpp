#include "menu.h"
#include <iostream>

namespace Menu
{
	void menuHelp()
	{
		std::cout << "****MENU****\n"
			"1) input matrix\n"
			"2) html type out based on Matrix&\n"
			"3) html type out based on Matrix& + string\n"
			"4) html type out based on vector\n"
			"5) html type out based on vector + string\n"
			"6) exit\n" << std::endl;
	}

	std::string inputString()
	{
		std::string str;
		std::cout << "input style of table(classic, modern, bold): " << std::flush;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (!std::getline(std::cin, str))
		{
			throw std::runtime_error("EOF");
		}

		return str;
	}

	void inputArgument(Matrix& matrix)
	{
		try
		{
			std::cout << "input count of lines in table: " << std::flush;
			int lines = Input::input();
			if (lines < 0)
			{
				throw std::invalid_argument("count of lines must be>= 0");
			}

			std::cout << "input length of line in table: " << std::flush;
			int length = Input::input();
			if (length < 0)
			{
				throw std::invalid_argument("length of lines must be >= 0");
			}

			if ((lines == 0 && length > 0) || (lines > 0 && length == 0))
			{
				throw std::invalid_argument("length and count of lines must be >= 0 or = 0");
			}

			size_t cnt_lines = lines;
			size_t len = length;

			if (matrix.lines)
			{
				freeMatrix(matrix);
			}
			matrix = createMatrix(len, cnt_lines);
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
	}

	void overLoad_1(const Matrix& matrix)
	{
		try
		{
			char* res = outputOfHtmlString(matrix);
			std::cout << res << std::endl;
			delete[] res;
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
	}

	void overLoad_2(const Matrix& matrix)
	{
		char* styleName = nullptr;

		try
		{
			std::string str = inputString();

			styleName = new char[str.length() + 1];
			std::strcpy(styleName, str.c_str());

			char* res = outputOfHtmlString(matrix, styleName);
			std::cout << res << std::endl;
			delete[] res;
			delete[] styleName;
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
			delete[] styleName;
			return;
		}
	}

	void overLoad_3(const Matrix& matrix)
	{
		try
		{
			std::vector<std::vector<int>> vectorMatrix = toVector(matrix);
			std::string res = outputOfHtmlString(vectorMatrix);
			std::cout << res << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
	}

	void overLoad_4(const Matrix& matrix)
	{
		try
		{
			std::string style = inputString();

			std::vector<std::vector<int>> vectorMatrix = toVector(matrix);
			std::string res = outputOfHtmlString(vectorMatrix, style);
			std::cout << res << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
			return;
		}
	}
}