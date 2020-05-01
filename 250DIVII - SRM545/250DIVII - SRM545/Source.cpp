#include <iostream>
#include <vector>
#include <string>

using namespace std;

int itOver(vector<int> &A, int n = 0);
int bitwiseAll(vector<int> &A, int n, int i = 0);

class ANDEquation {
public:

	int restoreY(vector <int> A)
	{
		return itOver(A, 0);
	}
};
int main()
{
	ANDEquation x;
	vector <int> vect {31, 7, 7};
	cout << x.restoreY(vect) << endl;
}

int itOver(vector<int> &A, int n)
{
	if (n >= A.size())
		return -1;
	if (bitwiseAll(A, n, 0) == A[n])
		return A[n];
	return itOver(A, n + 1);
}

int bitwiseAll(vector<int> &A, int n, int i)
{
	if (i >= A.size())
		return 2147483647;
	return (n != i) ? A[i] & bitwiseAll(A, n, i + 1) : bitwiseAll(A, n, i + 1);
}