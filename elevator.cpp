#include "elevator.h"

#include <iostream>
#include <cstdlib>
#include <vector>

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
	int y;
		for(int i=0;i<_floors;i++)
		{
			time+=_travel_time;
			if(is_passenger()==1)
			{	
				if(in_elevator)
				{
					for (int k=human.size()-1;k>=0;k--)
					{
						if (human[k]==i)
						{
							human.erase(human.begin()+k-1); 
							load--;
						}
					}
				}
				int x=rand() % 4;
				if(load<_max_load && (load+x)<=_max_load)
				{
					do
					{
						y=rand() % 5;
					}while(y!=i);
					human.push_back(y);
					load+=x;
					all_passenger=load;
					in_elevator=true;
				}

				time+=_stop_time;
				
			}
				cout << i << ". pietro, " << load << " pasazerow w windzie. Czas podrozy: " << time << endl;
		}
		for(int i=_floors-1;i>0;i--)
		{
			time+=_travel_time;
			if(is_passenger()==1)
			{	
				if(in_elevator)
				{
					for (int k=human.size()-1;k>=0;k--)
					{
						if (human[k]==i)
						{
							human.erase(human.begin()+k-1); 
							load--;
						}
					}
				}
				int x=rand() % 4;
				if(load<_max_load && (load+x)<=_max_load)
				{
					do
					{
						y=rand() % 5;
					}while(y!=i);
					human.push_back(y);
					load+=x;
					all_passenger=load;
					in_elevator=true;
				}

				time+=_stop_time;
				
			}
				cout << i << ". pietro, " << load << " pasazerow w windzie. Czas podrozy: " << time << endl;
		}


}

void elevator::result()
{
	cout << "Przewieziono " << all_passenger << " w czasie: " << time << endl;
}