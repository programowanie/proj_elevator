#include "elevator.h"

elevator::elevator(int floor_number):floor_number(floor_number), floor_button(floor_number, false)
{
	
}

void elevator::open_door()
{
	door_open=true;
}

void elevator::push_back_order(int height)
{
	orders_list.push_back(height);
}

void elevator::push_button(int floor)
{
	floor_button[floor]=true;
}

void elevator::speed_control()
{
	int destination_height=floor_by_height_function(orders_list.front());
	int height_difference=destination_height;
	int temp=abs(speed);
	int stop_distance=0;
	while(temp>0)
	{
		stop_distance+=(temp--);
	}
	stop_distance=(speed>0)?stop_distance:(-stop_distance);

	if(speed>0)
	{
		if(height+stop_distance>destination_height)
			--speed;
		if(height+stop_distance<destination_height)
			speed=(speed<max_speed)?(speed+1):max_speed;
	}
	else if (speed<0)
	{
		if(height+stop_distance>destination_height)
			speed=(speed>-max_speed)?(speed-1):-max_speed;
		if(height+stop_distance<destination_height)
			++speed;
	}
	else
	{
		if(height_difference>0)
			++speed;
		if(height_difference<0)
			--speed;
	}
}

void elevator::update()
{
	++time;
	
	speed_control();
	if(speed==0&&height==floor_by_height_function(orders_list.front()))
	{
		open_door();
		floor_button[orders_list.front()]=false;
		orders_list.pop_front();
	}

	height+=speed;
	cout << time << " " << height << " " << speed << endl;
}