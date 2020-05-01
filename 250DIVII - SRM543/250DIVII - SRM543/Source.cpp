#include <iostream>
#include <vector>
#include <string>

using namespace std;

class EllysTSP {
public:

	int getMax(string places)
	{
		int villages = 0, cities = 0;
		for (int i = 0; i < places.size(); i++)
		{
			if (places[i] == 'V')
				villages++;
			else
				cities++;
		}
		if (cities < villages)
			return 2 * cities + 1;
		else if (villages < cities)
			return 2 * villages + 1;
		return 2 * cities;
	}
};