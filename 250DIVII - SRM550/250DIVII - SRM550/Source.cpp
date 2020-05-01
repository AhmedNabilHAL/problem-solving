#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countSteps(string &s1, string &s2, int n);

class EasyConversionMachine {
public:

	string isItPossible(string originalWord, string finalWord, int k)
	{
		int steps = countSteps(originalWord, finalWord, finalWord.length() - 1);
		if (steps == k || (k > steps && (k - steps) % 2 == 0))
			return "POSSIBLE";
		return "IMPOSSIBLE";
	}
};
int countSteps(string &s1, string &s2, int n)
{
	if (n == 0)
		return (s1[n] != s2[n]) ? 1 : 0;
	return ((s1[n] != s2[n]) ? 1 : 0) + countSteps(s1, s2, n - 1);

}

int main()
{
	EasyConversionMachine x;
	cout << x.isItPossible("aababba", "bbbbbbb", 8) << endl;

}