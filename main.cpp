#include "elevator.h"
#include <cstdlib>
#include <iostream>
#include <unistd.h>


using namespace std;
int main (int argc, char const *argv[])
{
	int repeats = atoi(argv[1]);
	elevator test;
	cout << "\nWitaj w programie ' Symulator Windy ' v1.0. \nINFO: Winda bedzie sobie jezdzic na zasadzie gora-dol\nRozpocznijmy symulacje! \n" << endl;
	for (int i=0; i<repeats; i++)
	{	
		usleep(2000000);
		cout << "############### " << i+1 << ". TURA ###############" << endl;
		test.update();
		cout << endl;
	}
	test.result();
}