#include "elevator.h"
#include <cstdlib>
#include <iostream>


using namespace std;
int main (int argc, char const *argv[])
{
	int repeats = atoi(argv[1]);
	elevator test;
	cout << "\nWitaj w programie ' Symulator Windy ' v1.0. \nINFO: Winda bedzie sobie jezdzic na zasadzie gora-dol\nRozpocznijmy symulacje! \n" << endl;
	for (int i=0; i<repeats; i++)
	{	
		cout << "############### " << i+1 << ". TURA ###############" << endl;
		test.update();
		cout << endl;
	}
	test.result();
}