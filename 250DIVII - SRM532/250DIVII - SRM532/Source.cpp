#include <iostream>
#include <vector>

using namespace std;

void addNumber(vector <int> &numbersFound, int num);

class DengklekTryingToSleep {
public:

	int minDucks(vector <int> ducks)
	{
		vector <int> numbersFound;
		// iterate over ducks
		for (int i = 0; i < ducks.size(); i++)
		{
			addNumber(numbersFound, ducks[i]);
		}
		int inbetween = numbersFound[numbersFound.size() - 1] - numbersFound[0] - numbersFound.size() + 1;
		return inbetween;

	}
};

void addNumber(vector <int> &numbersFound, int num)
{
	int start = 0; int end = numbersFound.size() - 1;
	if (end == -1)
	{
		numbersFound.push_back(num);
		return;
	}
	int mid = (start + end) / 2;
	while (true)
	{
		if (numbersFound[mid] == num || start >= end)
			break;
		else if (num > numbersFound[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
		mid = (start + end) / 2;
	}
	numbersFound.push_back(num);
	if (num < numbersFound[mid])
	{
		for (int i = numbersFound.size() - 1; i > mid; i--)
			numbersFound[i] = numbersFound[i - 1];
		numbersFound[mid] = num;
	}
}
int main()
{
	vector <int> vect;
	addNumber(vect, 7);
	addNumber(vect, 4);
	addNumber(vect, 77);
	addNumber(vect, 47);
	addNumber(vect, 74);
	addNumber(vect, 44);
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
	cout << endl;
	DengklekTryingToSleep x;
	vector <int> vect1{ 7, 4, 77, 47, 74, 44 };
	cout << x.minDucks(vect1) << endl;
}