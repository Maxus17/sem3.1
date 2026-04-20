#ifndef MENU_H
#define MENU_H

#include "matrix.h"

using namespace Matr;

namespace Menu
{
	void menuHelp();
	void checkMatrix(const Matrix& matrix);
	std::string inputString();
	void inputArgument(Matrix& matrix);
	void overLoad_1(const Matrix& matrix);
	void overLoad_2(const Matrix& matrix);
	void overLoad_3(const Matrix& matrix);
	void overLoad_4(const Matrix& matrix);
}

#endif
