#include <iostream>
#include <math.h>
using namespace std;

class MagicalGirlLevelOneDivTwo {
public:

	double theMinDistance(int d, int x, int y)
	{
		int u, v;
		u = x - d;
		if (u < 0)
			u = 0;
		v = y - d;
		if (v < 0)
			v = 0;
		return sqrt((u * u + v * v));
	}
};

int main()
{
	return 0;
}