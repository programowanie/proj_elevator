#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class elevator
{
private:
	int _floors; //liczba pieter
	int _stop_time; //czas postoju na pietrze
	int _travel_time; //czas podrozy miedzy jednym a drugim pietrem (wartosc zmyslona)
	int _max_load; //max osob w windzie
	int load=0; //parametr liczacy osoby w windzie
	int time_simulation=-8; //parametr czasu podrozy
	int passenger=0 + rand() % 2;
	int is_passenger()
	{
		return passenger;
	}
	int all_passenger=0;
	bool in_elevator=false;
public:
	vector <int> human;
	elevator();
	int floors() {return _floors;}
	int stop_time() {return _stop_time;}
	int travel_time() {return _travel_time;}
	int max_load() {return _max_load;}
	
	void update();
	void result();

};