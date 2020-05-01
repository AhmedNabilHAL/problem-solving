#include <iostream>
#include <stdlib.h>

using namespace std;

class RandomColoringDiv2 {
public:

	int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2)
	{
		int ans = 0;
		for (int R = 0; R < maxR; R++)
		{
			for (int G = 0; G < maxG; G++)
			{
				for (int B = 0; B < maxB; B++)
				{
					if (abs(startB - B) <= d2 && abs(startR - R) <= d2 && abs(startG - G) <= d2 && (abs(startB - B) >= d1 || abs(startR - R) >= d1 || abs(startG - G) >= d1))
						ans++;

				}
			}
		}
		return ans;
	}
};