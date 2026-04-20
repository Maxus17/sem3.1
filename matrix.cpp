#include "matrix.h"
#include <iostream>
#include <format>
#include <numeric>

namespace Matr
{
	void freeMatrix(Matrix& matrix)
	{
		for (int i = 0; i < matrix.cnt_lines; i++)
		{
			freeLine(matrix.lines[i]);
		}
		delete[] matrix.lines;
		matrix.cnt_lines = 0;
	}

	Matrix createMatrix(size_t len, size_t cnt_lines)
	{
		Matrix matrix;
		try {
			matrix.lines = new Line[cnt_lines];
			matrix.cnt_lines = cnt_lines;

			for (size_t i = 0; i < matrix.cnt_lines; i++)
			{
				matrix.lines[i] = createLine(len);
				std::cout << std::format("input numbers in {} line", i + 1) << std::endl;
				inputLine(matrix.lines[i]);
			}
			return matrix;
		}
		catch (std::bad_alloc& e)
		{
			std::cout << "MEMORY_ERROR" << e.what() << std::endl;
			matrix.cnt_lines = 0;
			len = 0;
			throw;
		}
	}

	std::vector<std::vector<int>> toVector(const Matrix& matrix)
	{
		std::vector<std::vector<int>> vectorMatrix;
		for (size_t i = 0; i < matrix.cnt_lines; i++)
		{
			std::vector<int> vec;
			for (size_t j = 0; j < matrix.lines[i].len; j++)
			{
				vec.push_back(matrix.lines[i].arr[j]);
			}
			vectorMatrix.push_back(vec);
		}

		return vectorMatrix;
	}

	std::string changeStyle(const std::string& styleName)
	{
		if (styleName.empty())
		{
			return "border:1px solid black;";
		}
		if (styleName == "classic")
		{
			return "border:2px double #333";
		}
		else if (styleName == "modern") {
			return "border:1px dashed #666;";
		}
		else if (styleName == "bold") {
			return "border:3px solid red;";
		}
		else {
			throw std::invalid_argument("Unknown table style: " + styleName);
		}
	}

	std::string outputOfHtmlString(const std::vector<std::vector<int>>& matrix, const std::string& styleName)//overloead4
	{
		std::string style = changeStyle(styleName);

		std::string str = "<!DOCTYPE html>\n"
			"<html>\n"
			"<head>\n"
			"<style>\n"
			"table, th, td {\n" +
			style + ";\n"
			"}\n"
			"</style>\n"
			"</head>\n"
			"<body>\n"
			"<table>\n";


		str += std::accumulate(matrix.begin(), matrix.end(), std::string{}, [](const std::string& acc, const std::vector<int>& line)
			{
				std::string lineStr = "<tr>\n";
				lineStr += std::accumulate(line.begin(), line.end(), std::string{}, [](const std::string& acc, int val)
					{
						return acc + std::format("  <td>{}</td>\n", val);
					});
				lineStr += "</tr>\n";
				return acc + lineStr;
			});

		str += "</table>\n</body>\n</html>\n";
		return str;
	}

	std::string outputOfHtmlString(const std::vector<std::vector<int>>& matrix)//overload3
	{
		return outputOfHtmlString(matrix, std::string(""));
	}

	char* outputOfHtmlString(const Matrix& matrix, const char* styleName)//overloead2
	{
		try
		{
			std::vector<std::vector<int>> vectorMatrix = toVector(matrix);
			std::string str = outputOfHtmlString(vectorMatrix, std::string(styleName));

			char* res = new char[str.length() + 1];
			std::strcpy(res, str.c_str());

			return res;
		}
		catch (std::bad_alloc& e)
		{
			std::cout << "MEMORY_ERROR" << std::endl;
			return nullptr;
		}
	}

	char* outputOfHtmlString(const Matrix& matrix)//overload1
	{
		return outputOfHtmlString(matrix, "");
	}
}