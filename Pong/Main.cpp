#include <iostream>
#include "Pong.h"

using namespace std;


int main()
{
	try
	{
		Pong pong(800, 600);
		pong.Run();
	}
	catch ( exception& e )
	{
		cerr << e.what() << endl;
		cin.get();
	}

	return 0;
}
