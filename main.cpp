#include "elevator.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int main (int argc, char const *argv[])
{
	int repeats = atoi(argv[1]);
	elevator test;
	for (int i=0; i<repeats; i++)
	{
		cout << "############### " << i+1 << ". TURA ###############" << endl;
		test.update();
		cout << endl;
	}
	test.result();
}