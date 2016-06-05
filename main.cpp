#include "simulation.h"

using namespace std;
int main (int argc, char const *argv[])
{
	srand(time(NULL));
	elevator test(30);
	test.push_back_order(3);
	test.push_back_order(0);
	test.push_back_order(10);
	for (int i=0; i<100; i++)
	{
		test.update();
	}
}