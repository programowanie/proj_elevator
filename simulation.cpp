#include "simulation.h"

using namespace std;

simulation::simulation(int floor_number, int elevator_number): floor_number(floor_number), elevator_number(elevator_number), people_in_floor(floor_number, 0), button_in_floor(floor_number, make_pair(false, false)), elevator_list(elevator_number, elevator(floor_number))
{

}

int simulation::rand_range(int low, int high)
{
	return ((rand() % (high-low) ) + low );
}

void simulation::create_people(float probability_create, float probability_ground_floor)
{
	if(rand_range(0,10000)<100*probability_ground_floor)
	{
		if(rand_range(0,10000)<100*probability_ground_floor)
		{
			int temp+rand_range(0,floor_number-1);
			humans.push_back(human(ground_floor_number,(temp>=ground_floor_number)?(temp+1):temp));
			++people_in_floor[ground_floor_number];
		}
		else
		{
			int temp=rand_range(0,floor_number-1);
			int temp2=rand_range(0,floor_number-1);
			humans.push_back(human((temp>=ground_floor_number)?(temp+1):temp,(temp2>=temp)?(temp2+1):temp2));
			++people_in_floor[(temp>=ground_floor_number)?(temp+1):temp];
		}
	}
}