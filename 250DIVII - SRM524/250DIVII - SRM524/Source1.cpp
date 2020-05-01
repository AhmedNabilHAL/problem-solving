#include <iostream>
#include <vector>

using namespace std;
void addItem(vector <int> &factors, int n)
{
	factors.push_back(n);
	for (int i = 0; i < factors.size(); i++)
	{
		if (n > factors[i])
		{
			for (int j = i; j < factors.size() - 1; j++)
				factors[j + 1] = factors[j];
			factors[i] = n;
		}
	}
}

void printVector(vector <int> factors)
{
	for (int i = 0; i < factors.size(); i++)
		cout << factors[i] << endl;
}

int main()
{
	vector <int> factors{ 7, 5, 4, 2, 1};
	addItem(factors, 8);
	printVector(factors);
	addItem(factors, 6);
	printVector(factors);
	addItem(factors, 3);
	printVector(factors);
	addItem(factors, 0);
	printVector(factors);
	return 0;
}