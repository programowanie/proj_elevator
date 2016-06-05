#include "elevator.h"
#include "human.h"
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

class simulation
{
private:
	int floor_number;
	int ground_floor_number;
	int elevator_number;
	vector<pair<bool, bool>> button_in_floor;
	vector<elevator> elevator_list;

	int floor_by_height=100;
	int floor_by_height_function(int floor)
	{
		return floor_by_height*floor;
	}

	int time=0;

	void create_people(float probability_create, float probability_ground_floor);

	int rand_range(int low, int high);

public:
	simulation(int floor_number, int elevator_number);
};