#include <iostream>
#include <vector>
#include <string>

using namespace std;
int getSum(vector <int> percentages, unsigned int i);

int j = 0;
class ElectionFraudDiv2 {
public:

	string IsFraudulent(vector <int> percentages)
	{
		int sum = getSum(percentages, 0);
		if (sum + percentages.size() * 0.5 <= 100)
			return "YES";
		if (sum - (percentages.size() - j) * 0.5 > 100)
			return "YES";
		return "NO";
	}
	
};

int getSum(vector <int> percentages, unsigned int i)
{
	if (percentages[i] == 0)
		j++;
	if (i >= percentages.size() - 1)
		return percentages[i];
	
	return percentages[i] + getSum(percentages, i + 1);
}

int main()
{
	ElectionFraudDiv2 x;
	vector <int> vect{ 100, 1, 1, 0, 0, 0, 0 };
	cout << x.IsFraudulent(vect);
};
