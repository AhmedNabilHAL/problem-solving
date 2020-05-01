#include <iostream>
#include <vector>

using namespace std;

int findIntersections(string female, string male, string sibling);

class PlatypusPaternity {
public:

	int maxFamily(vector <string> femaleCompatibility, vector <string> maleCompatibility, vector <string> siblingGroups) 
	{
		int n = 0;
		int ans = -1;
		for (int i = 0; i < femaleCompatibility.size(); i++)
		{
			for (int j = 0; j < maleCompatibility.size(); j++)
			{
				for (int k = 0; k < siblingGroups.size(); k++)
				{
					n = findIntersections(femaleCompatibility[i], maleCompatibility[j], siblingGroups[k]);
					ans = (n > ans) ? n : ans;
				}
			}
		}
		return ans;
	}

	
};
int findIntersections(string female, string male, string sibling)
{
	int val = 0;
	int ln = female.length();
	for (int i = 0; i < ln; i++)
	{
		if (female[i] == 'Y' && male[i] == 'Y' && sibling[i] == 'Y')
			val++;
		else if (sibling[i] == 'Y')
			return 0;
	}
	return (val != 0) ? val + 2 : val;
}
int main()
{
	vector <string> f{ "YYYY", "YYYY" };
	vector <string> m{ "NNYN", "YYYN" };
	vector <string> s{ "YYYN", "NNNY" };
	PlatypusPaternity x;
	cout << x.maxFamily(f, m, s) << endl;
}
