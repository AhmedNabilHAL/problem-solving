#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FoxAndFlowerShopDivTwo {
public:

	int theMaxFlowers(vector <string> flowers, int r, int c)
	{
		int n = 0;
		int max = 0;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < flowers[0].length(); j++)
			{
				if (flowers[i][j] == 'F')
					n++;
			}
		}
		max = n;
		n = 0;
		
		for (int i = 0; i < flowers.size(); i++)
		{
			for (int j = c + 1; j < flowers[0].length(); j++)
			{
				if (flowers[i][j] == 'F')
					n++;
			}
		}
		max = (n > max) ? n : max;
		n = 0;
		for (int i = r + 1; i < flowers.size(); i++)
		{
			for (int j = 0; j < flowers[0].length(); j++)
			{
				if (flowers[i][j] == 'F')
					n++;
			}
		}
		max = (n > max) ? n : max;
		n = 0;
		for (int i = 0; i < flowers.size(); i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (flowers[i][j] == 'F')
					n++;
			}
		}
		max = (n > max) ? n : max;
		n = 0;
		return max;
	}
};