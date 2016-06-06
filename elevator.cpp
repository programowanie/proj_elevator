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
	int passenger_in=0;
	int passenger_out=0;
	int passenger_in_elev=0;
	int y;
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
			
			if(is_passenger()==1)
			{	
				if(in_elevator)
				{
					for (int k=human.size()-1;k>=0;k--)
					{
						if (human[k]==i)
						{
							human.erase(human.begin()+k-1); 
							passenger_out++;
						}
						load=load-passenger_out;
						passenger_in_elev=load;
						if (load==0)
						{
							in_elevator==false;
							continue;
						}
					}
					cout << "Wysiadlo " << passenger_out << " pasazerow." << endl;
				}
				passenger_in=rand() % 7;
				if(load<e_max_load && (load+passenger_in)<=e_max_load)
				{
					do
					{
						y=rand() % 5;
					}while(y!=i);
					human.push_back(y);
					load+=passenger_in;
					passenger_in_elev=load;
					all_passenger+=passenger_in;
					in_elevator=true;
				}
				cout << "Wsiadlo " << passenger_in << " pasazerow." << endl;
				cout << "Pasazerow w windzie: " << load << endl;
				if(passenger_in!=0 || passenger_out!=0)
				{
					time_simulation+=e_stop_time;
				}
				passenger_out=0;
				passenger_in=0;
			}
			time_simulation+=e_travel_time;
				cout << "Czas podrozy: " << time_simulation << endl;
				cout << endl;
		}
		load=passenger_in_elev;
		for(int i=e_floors-2;i>0;i--) // winda w dol
		{
			if(i==0)
			{
				cout << "Parter"<< endl;	
			}
			else
			{
				cout << i << ". Pietro"<< endl;
			}
			
			if(is_passenger()==1)
			{	
				if(in_elevator)
				{
					for (int k=human.size()-1;k>=0;k--)
					{
						if (human[k]==i)
						{
							human.erase(human.begin()+k-1); 
							passenger_out++;
						}
						load=load-passenger_out;
						if (load==0)
						{
							in_elevator==false;
							continue;
						}
					}
					cout << "Wysiadlo " << passenger_out << " pasazerow." << endl;
				}
				passenger_in=rand() % 7;
				if(load<e_max_load && (load+passenger_in)<=e_max_load)
				{
					do
					{
						y=rand() % e_floors;
					}while(y!=i);
					human.push_back(y);
					load+=passenger_in;
					all_passenger+=passenger_in;
					in_elevator=true;
				}
				cout << "Wsiadlo " << passenger_in << " pasazerow." << endl;
				cout << "Pasazerow w windzie: " << load << endl;
				if(passenger_in!=0 || passenger_out!=0)
				{
					time_simulation+=e_stop_time;
				}
				passenger_out=0;
				passenger_in=0;
				
			}
			time_simulation+=e_travel_time;
				cout << "Czas podrozy: " << time_simulation << endl;
				cout << endl;
		}
		load=passenger_in_elev;


}

void elevator::result()
{
	cout << "Przewieziono " << all_passenger << " pasazerow w czasie: " << time_simulation << " sekund." << endl;
}