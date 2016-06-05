#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

class elevator
{
private:
	int height=0;
	int speed=0;
	const int max_speed=10;

	int time=0;

	int floor_number;
	vector<bool> floor_button;
	list<int> orders_list;

	int floor_by_height=100;
	int floor_by_height_function(int floor) 
	{
		return floor_by_height*floor;
	}

	bool door_open=false;
	bool is_door_open()
	{
		return door_open;
	}

	void speed_control();
	void open_door();
	void close_door();

public:
	
	void update();
	elevator(int floor_number);
	void push_back_order(int height);
	void push_button(int floor);


};