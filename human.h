#pragma once

class human
{
private:
	int initial_floor;
	int destination_floor;
	int time=0;
	int waiting_time=0;
	bool in_elevator=false;
	bool in_destination_floor=false;
public:
	human(int initial_floor, int destination_floor);
};