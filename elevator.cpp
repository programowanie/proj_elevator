#include "elevator.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

elevator::elevator()
{
	_floors=5;
	_stop_time=6;
	_max_load=20;
	_travel_time=8;
}

void elevator::update()
{
	int passenger_in=0;
	int passenger_out=0;
	int passenger_in_elev=0;
	srand(time(NULL));
	int y;
		for(int i=0;i<_floors;i++)
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
				if(load<_max_load && (load+passenger_in)<=_max_load)
				{
					do
					{
						y=rand() % _floors;
					}while(y!=i);
					human.push_back(y);
					load+=passenger_in;
					all_passenger+=load;
					in_elevator=true;
				}
				cout << "Wsiadlo " << passenger_in << " pasazerow." << endl;
				cout << "Pasazerow w windzie: " << load << endl;
				time_simulation+=_stop_time;
				passenger_in=0;
			}
			time_simulation+=_travel_time;
				cout << "Czas podrozy: " << time_simulation << endl;
				cout << endl;
		}
		passenger_in_elev=load;
		for(int i=_floors-2;i>0;i--)
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
						passenger_in_elev=passenger_in_elev-passenger_out;
						if (passenger_in_elev==0)
						{
							in_elevator==false;
							continue;
						}
					}
					cout << "Wysiadlo " << passenger_out << " pasazerow." << endl;
				}
				passenger_in=rand() % 7;
				if(passenger_in_elev<_max_load && (passenger_in_elev+passenger_in)<=_max_load)
				{
					do
					{
						y=rand() % _floors;
					}while(y!=i);
					human.push_back(y);
					passenger_in_elev+=passenger_in;
					all_passenger+=passenger_in_elev;
					in_elevator=true;
				}
				cout << "Wsiadlo " << passenger_in << " pasazerow." << endl;
				cout << "Pasazerow w windzie: " << passenger_in_elev << endl;
				time_simulation+=_stop_time;
				passenger_in=0;
				
			}
			time_simulation+=_travel_time;
				cout << "Czas podrozy: " << time_simulation << endl;
				cout << endl;
		}
		load=passenger_in_elev;


}

void elevator::result()
{
	cout << "Przewieziono " << all_passenger << " w czasie: " << time_simulation << endl;
}