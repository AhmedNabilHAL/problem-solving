#include <iostream>
#include <string>

using namespace std;

int isTuple(string S, string substring, int n);

class AkariDaisukiDiv2 {
public:


	int countTuples(string S)
	{
		int ln = S.length();
		int ans = 0;
		// iterate over string
		string substring = "";
		for (int i = 0; i < ln; i++)
		{
			// substring = ""
			substring = "";
			// for j = i to j = ln - 1
			for (int j = i; j < ln; j++)
			{
				// substring += S[j]
				substring += S[j];
				// if it forms a tuple ans++
				int k = isTuple(S, substring, i);
				if (k > 0)
					ans += k;
				// else break
				else
					break;
			}
		}
		return ans;
	}
};

int isTuple(string S, string substring, int n)
{
	int times_found = 0;
	int ln = S.size();
	int subln = substring.length();
	bool found = false;
	int pt = 0;
	// if nothing before substring or nothing after substring return false
	if (n <= 0 || n >= ln - 1)
		return 0;
	// search for substring from n + sublen + 1 to  ln -1 (+1 bec atleast one char has to divide the equiv substrings else imagine you didn't find it)
	int i;
	for (i = n + subln + 1; i < ln; i++)
	{
		if (S[i] == substring[0])
		{
			found = true;
			for (int j = 1; j < subln; j++)
			{
				if (S[i + j] != substring[j])
				{
					found = false;
					break;
				}
			}
		}
		if (found)
		{
			pt = i;
			times_found++;
			found = false;
		}
	}


	// if nothing after it or not found return false
	if (times_found <= 0)
		return 0;
	if (pt + subln - 1 >= ln - 1)
		times_found--;
	// return true
	return times_found;

}
int main()
{
	AkariDaisukiDiv2 x;
	cout << x.countTuples("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
}