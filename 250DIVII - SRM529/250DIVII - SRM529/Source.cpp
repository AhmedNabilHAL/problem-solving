#include <iostream>
#include <vector>

using namespace std;

class PairingPawns {
public:

	int savedPawnCount(vector <int> start)
	{
		// iterate over vector backwards untill i = 1
		for (int i = start.size() - 1; i >= 1; i--)
		{
			// while (start[i] > 1)
			while (start[i] > 1)
			{

				// start[i] -= 2
				start[i] -= 2;
				// start[i - 1]++;
				start[i - 1]++;
			}
		}
		//return start[0]
		return start[0];
	}
};

int main()
{
	PairingPawns x;
	vector <int> vect{0, 2};
	cout << x.savedPawnCount(vect) << endl;
	return 0;
}

int main()
{
	PairingPawns x;
	vector <int> vect{0, 2};
	cout << x.savedPawnCount(vect) << endl;
	return 0;
}