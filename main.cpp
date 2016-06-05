#include "elevator.h"
#include <cstdlib>
#include <iostream>
using namespace std;
int main (int argc, char const *argv[])
{
	srand(time(NULL));
	elevator test;
	for (int i=0; i<5; i++)
	{
		test.update();
	}
	test.result();
}