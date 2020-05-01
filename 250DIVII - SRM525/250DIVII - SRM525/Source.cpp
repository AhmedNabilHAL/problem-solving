#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RainyRoad {
public:

	string isReachable(vector <string> road)
	{
		int i = 0;
		while (i < road[0].length())
		{
			if (road[0][i] == '.' || road[1][i] == '.')
				i++;
			else
				return "NO";
		}
		return "YES";
	}
};

int main()
{
	RainyRoad x;
	vector <string> vect{ ".W..", "...." };
	cout << x.isReachable(vect) << endl;
}