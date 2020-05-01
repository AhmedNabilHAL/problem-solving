#include <iostream>
#include <vector>

using namespace std;
bool isFortunate(int num);

bool isFound(int num, vector <int> &found);


class FortunateNumbers {
public:

	int getFortunate(vector <int> a, vector <int> b, vector <int> c)
	{
		vector <int> found;
		int lna = a.size();
		int lnb = b.size();
		int lnc = c.size();
		int ans = 0;
		int num;
		for (int i = 0; i < lna; i++)
		{
			for (int j = 0; j < lnb; j++)
			{
				for (int k = 0; k < lnc; k++)
				{
					num = a[i] + b[j] + c[k];
					if (isFortunate(num) && !(isFound(num, found)))
					{
						ans++;
						found.push_back(num);
					}
				}
			}
		}
		return ans;
	}

};

int main()
{
	FortunateNumbers x;
	cout << x.getFortunate({1,10,100}, {3,53}, {4,54}) << endl;
}



bool isFortunate(int num)
{
	int fortunates = 0;
	int size = 0;
	while (num != 0)
	{
		size++;
		if (num % 10 == 5 || num % 10 == 8)
			fortunates++;
		num /= 10;
	}
	if (fortunates == size)
		return true;
	return false;
}

bool isFound(int num, vector <int> &found)
{
	for (int i = 0; i < found.size(); i++)
	{
		if (num == found[i])
			return true;
	}
	return false;
}