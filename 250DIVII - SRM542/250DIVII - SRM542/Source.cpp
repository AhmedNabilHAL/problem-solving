#include <iostream>
#include <vector>
#include <string>

using namespace std;

class WorkingRabbits {
public:

	double getEfficiency(vector <string> profit)
	{
		int rabbits = profit.size();
		double p = 0;
		int q = 0;
		for (int i = 0; i < rabbits; i++)
		{
			for (int j = i + 1; j < rabbits; j++)
			{
				p += (int)profit[i][j] - (int)'0';
				q++;
			}
		}
		if (!q)
			return 0;

		return p / q;
	}
};

int main()
{
	WorkingRabbits x;
	vector <string> vect{ "071",
		"702",
		"120" };
	cout << x.getEfficiency(vect) << endl;
	return 0;
}