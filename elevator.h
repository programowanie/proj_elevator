#include <iostream>
#include <cstdlib>
#include <list>
using namespace std;

class elevator
{
private:
	int e_floors; //liczba pieter
	int e_stop_time; //czas postoju na pietrze
	int e_travel_time; //czas podrozy miedzy jednym a drugim pietrem (wartosc zmyslona)
	int e_max_load; //max osob w windzie
	int load=0; //parametr liczacy osoby w windzie
	int time_simulation=-8; //parametr czasu podrozy
	int temp=0;
	/*int passenger=0 + rand() % 2;
	int is_passenger()
	{									// warunek logiczny na int odnośnie sprawdzania czy na pietrze byli pasazerowie (usuniety po ver alpha)
		return passenger;
	}*/
	int all_passenger=0;
	bool in_elevator=false;
public:
	list <int> human;
	elevator();
	int floors() {return e_floors;}
	int stop_time() {return e_stop_time;}
	int travel_time() {return e_travel_time;}
	int max_load() {return e_max_load;}
	
	void update();
	void result();

};