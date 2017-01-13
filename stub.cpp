#define _CRTDBG_MAP_ALLOC

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <crtdbg.h>

#include "List.h"
#include "Node.h"
#include "Exception.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	List<string> stringlist;
	
	//try
	//{
	//	stringlist.First();
	//}
	//catch (Exception &exception)
	//{
	//	cout << exception.getMessage();
	//}
	//try
	//{
	//	stringlist.Last();
	//}catch (Exception &exception)
	//{ 
	//	cout << exception.getMessage();
	//}

	stringlist.Append(string("1stAppend"));
	stringlist.Append(string("secondAppend"));
	stringlist.PrintForwards();
	cout << "\n";
	stringlist.Prepend("Prepend should be in front");
	stringlist.Prepend("last prepend");
	stringlist.PrintBackwards();
	cout << "\n";
	stringlist.PrintForwards();
	stringlist.Extract("Prepend should be in front");
	cout << "\n";
	stringlist.PrintForwards();
	cout << "\n";
	List<string> secondstringlist;
	stringlist.InsertBefore("Prepend should be in front", "Work");
	stringlist.InsertAfter("Prepend should be in front", "Work");
	secondstringlist = stringlist;
	secondstringlist.PrintForwards();

	return 0;
}