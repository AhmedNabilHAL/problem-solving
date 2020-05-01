#include <iostream>
#include <string>
using namespace std;

int matching(string s, int);

class TwiceString {
public:


	string getShortest(string s)
	{
		int ln = s.length();
		string ans = s;
		int m = 0;
		if ((m = matching(s, ln)) != 0)
		{
			string str;
			for (int i = m; i < ln; i++)
			{
				str = s[i];
				ans.append(str);
			}
			return ans;
		}

		return s.append(s);
	}
};
int main()
{
	TwiceString x;
	cout << x.getShortest("mzbzgqfsmnkoililhtimmzbzg") << endl;
	return 0;
}

int matching(string s, int ln)
{
	int matches = 0;
	for (int j = 1; j < ln; j++)
	{
		if (s[matches] == s[j])
		{
			matches++;
			
		}
		else
		{
			matches = 0;
			if (s[matches] == s[j])
			{
				matches++;

			}
		}
		
	}
	return matches;
}