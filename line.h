#ifndef LINE_H
#define LINE_H

#include "inp.h"

namespace Matr
{
	struct Line {
	size_t len = 0;
	int* arr = nullptr;
	};

	void freeLine(Line& line);
	Line createLine(size_t len);
	void inputLine(Line& line);
}


#endif
