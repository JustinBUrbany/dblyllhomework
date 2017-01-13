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
	List<string>secondstringlist;

	try
	{
		stringlist.First();
	}
	catch (Exception &exception)
	{
		cout << exception.getMessage()<<'\n';
	}
	try
	{
		stringlist.Last();
	}catch (Exception &exception)
	{ 
		cout << exception.getMessage()<<'\n';
	}
	try
	{
		stringlist.PrintForwards();
	}catch(Exception &exception)
	{
		cout << exception.getMessage() << '\n';
	}
	try
	{
		stringlist.PrintBackwards();
	}catch (Exception &exception)
	{
		cout << exception.getMessage() << '\n';
	}
	try
	{
		stringlist.Extract("something");
	}catch (Exception &exception)
	{
		cout << exception.getMessage() << '\n';
	}
	stringlist.Append("1stAppend");
	try
	{
		stringlist.InsertAfter("asfd", "work");
	}catch (Exception &exception)
	{
		cout << exception.getMessage() << '\n';
	}
	try
	{
		stringlist.InsertBefore("asdf", "work");
	}catch(Exception &exception)
	{
		cout << exception.getMessage() << '\n';
	}
	

	stringlist.Append("secondAppend");
	stringlist.PrintForwards();
	cout << "\n";
	stringlist.Prepend("firstprepend");
	stringlist.Prepend("lastprepend");
	stringlist.PrintBackwards();
	cout << "\n";
	stringlist.PrintForwards();

	cout << "\n";
	stringlist.PrintForwards();
	cout << "\n";

	stringlist.InsertBefore("firstprepend", "Work");
	stringlist.InsertBefore("lastprepend", "insertbeforehead");
	stringlist.InsertBefore("secondAppend", "insertbeforeTail");

	try
	{
		stringlist.Extract("something");
	}
	catch (Exception &exception)
	{
		cout << exception.getMessage() << '\n';
	}

	cout << "\n";
	stringlist.PrintForwards();

	stringlist.InsertAfter("firstprepend", "Work");
	stringlist.InsertAfter("insertbeforehead", "insertafterhead");
	stringlist.InsertAfter("secondAppend", "insertaftertail");

	cout << "\n";
	stringlist.PrintForwards();

	stringlist.Extract("insertbeforehead");

	cout << "\n";
	stringlist.PrintForwards();

	secondstringlist = stringlist;

	cout << "\n";
	secondstringlist.PrintForwards();

	cout << "\n" << secondstringlist.getHead() << ' ' << secondstringlist.getTail() << "\n";


	//Test 2 with pointers works you don't new the secondlist so you don't have to delete it
	List<string> * pointerstringlist = new List<string>;
	List<string> * secondpointerlist =pointerstringlist;

	pointerstringlist->Append(string("1stAppend"));
	pointerstringlist->Append(string("secondAppend"));
	pointerstringlist->PrintForwards();
	cout << "\n";
	pointerstringlist->Prepend("firstprepend");
	pointerstringlist->Prepend("lastprepend");
	pointerstringlist->PrintBackwards();
	cout << "\n";
	pointerstringlist->PrintForwards();
	cout << "\n";
	pointerstringlist->PrintForwards();
	cout << "\n";
	pointerstringlist->InsertBefore("firstprepend", "Work");
	pointerstringlist->InsertBefore("lastprepend", "insertbeforehead");
	pointerstringlist->InsertBefore("secondAppend", "insertbeforeTail");
	cout << "\n";
	pointerstringlist->PrintForwards();
	pointerstringlist->InsertAfter("firstprepend", "Work");
	pointerstringlist->InsertAfter("insertbeforehead", "insertafterhead");
	pointerstringlist->InsertAfter("secondAppend", "insertaftertail");
	cout << "\n";
	pointerstringlist->PrintForwards();
	pointerstringlist->Extract("insertbeforehead");
	cout << "\n";
	pointerstringlist->PrintForwards();
	cout << "\n";
	pointerstringlist->PrintForwards();

	secondpointerlist=pointerstringlist;
	cout << "\n" << secondpointerlist->getHead() << ' ' << secondpointerlist->getTail() << "\n";
	pointerstringlist->Extract("insertaftertail");
	cout << "\n" << secondpointerlist->First() << ' ' << secondpointerlist->Last() << "\n";
	cout << "\n" << pointerstringlist->First() << ' ' << pointerstringlist->Last() << "\n";


	delete pointerstringlist;
	pointerstringlist = nullptr;
	

	List<int> intlist;
	List<int> intlist2;


	intlist.Append(44);
	intlist.Append(55);
	intlist.PrintForwards();
	cout << "\n";
	intlist.Prepend(79);
	intlist.Prepend(33);
	intlist.PrintBackwards();
	cout << "\n";
	intlist.PrintForwards();
	cout << "\n";
	intlist.PrintForwards();
	cout << "\n";
	intlist.InsertBefore(79, 1);
	intlist.InsertBefore(33, 2);
	intlist.InsertBefore(55, 3);
	cout << "\n";
	intlist.PrintForwards();
	intlist.InsertAfter(79, 4);
	intlist.InsertAfter(2, 5);
	intlist.InsertAfter(55, 6);
	cout << "\n";
	intlist.PrintForwards();
	intlist.Extract(3);
	cout << "\n";
	intlist.PrintForwards();
	cout << "\n";
	intlist.PrintForwards();

	intlist2 = intlist;
	cout << "\n" << intlist2.getHead() << ' ' << intlist2.getTail() << "\n";
	intlist.Extract(6);
	cout << "\n" << intlist2.First() << ' ' << intlist2.Last() << "\n";
	cout << "\n" << intlist.First() << ' ' << intlist.Last() << "\n";


	List<char>  charlist;
	List<char> charlist2;

	charlist.Append('4');
	charlist.Append('a');
	charlist.PrintForwards();
	cout << "\n";
	charlist.Prepend('7');
	charlist.Prepend('3');
	charlist.PrintBackwards();
	cout << "\n";
	charlist.PrintForwards();
	cout << "\n";
	charlist.PrintForwards();
	cout << "\n";
	charlist.InsertBefore('7', '1');
	charlist.InsertBefore('3', '2');
	charlist.InsertBefore('a', '3');
	cout << "\n";
	charlist.PrintForwards();
	charlist.InsertAfter('7', '8');
	charlist.InsertAfter('2', '9');
	charlist.InsertAfter('a', 'b');
	cout << "\n";
	charlist.PrintForwards();
	charlist.Extract('3');
	cout << "\n";
	charlist.PrintForwards();
	cout << "\n";
	charlist.PrintForwards();

	charlist2 = charlist;
	cout << "\n" << charlist2.getHead() << ' ' << charlist2.getTail() << "\n";
	charlist.Extract('2');
	cout << "\n" << charlist2.First() << ' ' << charlist2.Last() << "\n";
	cout << "\n" << charlist.First() << ' ' << charlist.Last() << "\n";


	return 0;
}