#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BallAndHats {
public:

	int getHat(string hats, int numSwaps)
	{
		int inti = -1;
		for (int i = 0; i < hats.length(); i++)
		{
			if (hats[i] == 'o')
				inti = i;
		}
		// get intital ball position
		if (numSwaps == 0)
			return inti;
		// if its in the middle then
		if (inti == 1)
			// if swaps is even then return 1
			if (numSwaps % 2 == 0)
				return 1;
			// else return 0
			else
				return 0;

		// if swaps is odd then return 1
		if (numSwaps % 2)
			return 1;
		// else return 0
		return 0;
		
	}
};