#ifndef MATRIX_H
#define MATRIX_H

#include "line.h"
#include <vector>
#include <string>

namespace Matr
{
	struct Matrix
	{
		size_t cnt_lines = 0;
		Line* lines = nullptr;
	};

	void freeMatrix(Matrix& matrix);
	Matrix createMatrix(size_t len, size_t cnt_lines);
	std::vector<std::vector<int>> toVector(const Matrix& matrix);
	std::string changeStyle(const std::string& styleName);
	std::string outputOfHtmlString(const std::vector<std::vector<int>>& matrix, const std::string& styleName);
	std::string outputOfHtmlString(const std::vector<std::vector<int>>& matrix);
	char* outputOfHtmlString(const Matrix& matrix, const char* styleName);
	char* outputOfHtmlString(const Matrix& matrix);
}


#endif
