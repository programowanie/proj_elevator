#include "elevator.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

elevator::elevator()
{
	e_floors=5;
	e_stop_time=6;
	e_max_load=20;
	e_travel_time=8;
	srand(time(NULL));
}

void elevator::update()
{
		for(int i=0;i<e_floors;i++) //winda do gory
		{
			if(i==0)
			{
				cout << "Parter"<< endl;	
			}
			else
			{
				cout << i << ". Pietro"<< endl;
			}
			
			load=human.size(); // ilosc osob w windzie
			human.remove(i); // usuwamy te osoby ktore chcialy wysiasc na tym pietrze
			int people_out = load-human.size();  //ile wysiadlo osob
			load=human.size();  // ile zostalo
			all_passenger+=people_out;

			//wsiadanie do windy

			int people_want_in = rand()%7; //losujemy ile osob czeka na danym pietrze
			int people_in = ((max_load()-load) >= people_want_in) ? people_want_in : (max_load()-load);
			//ile osob tak naprawde wejdzie
			load+=people_in;

			for (int j=0; j<people_in; j++)
			{
				int want_floor=rand()%e_floors-1;
				human.push_back(want_floor>=i?(want_floor+1):want_floor); //przypisuje chciane piętro
			}

			if(people_in!=0 || people_out!=0)
				{
					time_simulation+=e_stop_time;
				}
				time_simulation+=e_travel_time;

			if(i==0)
				{
					load-=temp;
					cout << " Wsiadlo: " << people_in << "\n Ludzi w windzie: " << load << endl;
					cout << " Czas podrozy: " << time_simulation << endl;
				}
				else
				{
					cout << " Wsiadlo: " << people_in << "\n Wysiadlo: " << people_out << "\n Ludzi w windzie: " << load << endl;
					cout << " Czas podrozy: " << time_simulation << endl;
				}	
			
			
		}


			for(int i=e_floors-2;i>=0;i--) //winda w dol
		{
			if(i==0)
			{
				cout << "Parter"<< endl;	
			}	
			else
			{
				cout << i << ". Pietro"<< endl;
			}
			
			load=human.size(); // ilosc osob w windzie
			human.remove(i); // usuwamy te osoby ktore chcialy wysiasc na tym pietrze
			int people_out = load-human.size();  //ile wysiadlo osob
			load=human.size();  // ile zostalo
			all_passenger+=people_out;	

			//wsiadanie do windy

			int people_want_in = rand()%7; //losujemy ile osob czeka na danym pietrze
			int people_in = ((max_load()-load) >= people_want_in) ? people_want_in : (max_load()-load);
			//ile osob tak naprawde wejdzie
			load+=people_in;

			for (int j=0; j<people_in; j++)
			{
				int want_floor=rand()%e_floors-1;
				human.push_back(want_floor>=i?(want_floor+1):want_floor); //przypisuje chciane piętro
			}

			if(people_in!=0 || people_out!=0)
				{
					time_simulation+=e_stop_time;
				}
				time_simulation+=e_travel_time;
				if(i==0)
				{
					temp=people_in;
					load-=temp;
					people_in=0;
					cout << " Wysiadlo: " << people_out << "\n Ludzi w windzie: " << load << endl;
					cout << " Czas podrozy: " << time_simulation << endl;
				}
				else
				{
					cout << " Wsiadlo: " << people_in << "\n Wysiadlo: " << people_out << "\n Ludzi w windzie: " << load << endl;
					cout << " Czas podrozy: " << time_simulation << endl;
				}				
			
		
		}

}

void elevator::result()
{
	cout << "Przewieziono " << all_passenger << " pasazerow w czasie: " << time_simulation << " sekund." << endl;
}