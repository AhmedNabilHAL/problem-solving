#include <iostream>

using namespace std;

class MinCostPalindrome {
public:

	int getMinimum(string s, int oCost, int xCost)
	{
		int ans = 0;
		// iterate over array both backward and forwards untill ln/2- 1 and ln/2 respec
		int ln = s.length();
		int i = 0, j = ln - 1; int mid = ln / 2;
		while (j >= mid)
		{

			// if one of them is known and the other ? turn ? to the known one
			if (s[i] != '?' && s[j] == '?')
			{
				if (s[i] == 'o')
					ans += oCost;
				else
					ans += xCost;
			}
			else if (s[j] != '?' && s[i] == '?')
			{
				if (s[j] == 'o')
					ans += oCost;
				else
					ans += xCost;
			}
			// else if both aren't known change both them to o,x lower cost one bet (o,x)
			else if (s[i] == '?' && s[j] == '?')
				ans = (oCost < xCost) ? ans + oCost * 2 : ans + xCost * 2;
			else if (s[i] != s[j])
				return -1;

			i++;
			j--;
		}
		return ans;
	}
};