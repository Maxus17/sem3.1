#define _CRTDBG_MAP_ALLOC
#include "menu.h"
#include <iostream>
#include <cstdlib> 
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif

using namespace Menu;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Matrix matrix;
	try
	{
		int ent = -1;

		while (ent)
		{
			menuHelp();
			ent = Input::input();

			switch (ent)
			{
				case 1:
					inputArgument(matrix);
					break;
				case 2:
					overLoad_1(matrix);
					break;
				case 3:
					overLoad_2(matrix);
					break;
				case 4:
					overLoad_3(matrix);
					break;
				case 5:
					overLoad_4(matrix);
					break;
				case 6:
					std::cout << "exit" << std::endl;
					freeMatrix(matrix);
					return 0;
				default:
					std::cout << "don`t know this number\n" << std::endl;
					break;
			}
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	freeMatrix(matrix);
	return 0;
}