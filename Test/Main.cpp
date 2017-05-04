#include <iostream>
#include "Test.h"

using namespace std;


int main()
{
	try
	{
		Test test;
		test.Run();
	}
	catch ( exception& e )
	{
		cout << e.what() << endl;
		cin.get();
	}

    return 0;
}
