#include <iostream>
#include <vector>


using namespace std;

void addItem(vector <int> &factors, int i);

class ShippingCubes {
public:


	int minimalCost(int N)
	{
		int ans = -1;
		int res;
		for (int i = 1; i <= N; i++)
		for (int j = 1; i * j <= N; j++)
		for (int k = 1; k * j * i <= N; k++)
		if ((k * j * i) == N)
		{
			res = k + i + j;
			ans = (ans < res && ans != -1) ? ans : res;
		}
		return ans;

	}
};

int main()
{
	ShippingCubes x;
	cout << x.minimalCost(180) << endl;
	return 0;
}