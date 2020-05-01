#include <iostream>
#include <vector>

using namespace std;

class PointErasingTwo {
public:


	int getMaximum(vector <int> y)
	{
		unsigned int ln = y.size();
		int ans = 0;
		int temp = 0;
		// iterate over vector y backwards
		for (int i = ln - 1; i >= 0; i--)
		{
			// for j = 0 to j = i
			for (int j = 0; j < i; j++)
			{
				temp = 0;
				// iterate over what's between j and i
				for (int k = j + 1; k < i; k++)
				{
					int upper_limit = (y[i]>y[j]) ? y[i] : y[j];
					int lower_limit = (y[i] < y[j]) ? y[i] : y[j];
					// if y[k] > upperlimit and y[j] is smaller than lowerlimit then add one to ans
					if (y[k] < upper_limit && y[k] > lower_limit)
						temp++;
				}
				// if ans is bigger than prev ans then change it
				ans = (ans > temp) ? ans : temp;
			}
		}
		return ans;
	}
};