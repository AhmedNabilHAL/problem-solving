#include <iostream>
#include <string>
#include <vector>
using namespace std;

class P8XMatrixTransformation {
public:

	string solve(vector <string> original, vector <string> target)
	{
		int countO = 0;
		int countT = 0;
		for (int i = 0; i < original.size(); i++)
		{
			for (int j = 0; j < original[0].length(); j++)
			{
				if (original[i][j] == '1')
					countO++;
				if (target[i][j] == '1')
					countT++;
			}
		}
		if (countT != countO)
			return "NO";
		return "YES";
	}
};