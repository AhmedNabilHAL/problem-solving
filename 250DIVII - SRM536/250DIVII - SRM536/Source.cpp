#include <iostream>
#include <vector>

using namespace std;

class BinaryPolynomialDivTwo {
public:

	int countRoots(vector <int> a) {
		int ln = a.size();
		int sum = 0, sum1 = 0;
		int ans = 0;
		for (int i = 0; i < ln; i++)
		{
			if (i == 0)
			{
				sum += a[i] * 1;
				sum1 += a[i] * 1;
			}
			else
			{
				sum += a[i] * 0;
				sum1 += a[i] * 1;
			}
		}
		if (sum % 2 == 0)
			ans++;
		if (sum1 % 2 == 0)
			ans++;
		return ans;
		
	}
};