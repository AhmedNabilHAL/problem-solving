#include <iostream>
#include <vector>

using namespace std;
int A = 0, B = 1, C = 2;
class CheatingQuiz {
public:

	vector <int> howMany(string answers)
	{
		// abcaaa -> 3,3,2,1,1,1
		// count the number of As Bs and Cs
		int ln = answers.length();
		vector<int> options{ 0, 0, 0 };
		vector <int> ans;
		for (int i = 0; i < ln; i++)
		{
			if (answers[i] == 'A')
				options[A]++;
			else if (answers[i] == 'B')
				options[B]++;
			else
				options[C]++;
		}
		// iterate over answers
		for (int i = 0; i < ln; i++)
		{
			int temp = 0;
			// if an option(a,b,c) has > 0  then +1 options to this question
			for (int j = 0; j < 3; j++)
			{
				if (options[j] > 0)
					temp++;
			}
			ans.push_back(temp);
			// read answers[i] then -1 to whatever option
			if (answers[i] == 'A')
				options[A]--;
			else if (answers[i] == 'B')
				options[B]--;
			else
				options[C]--;
		}
		return ans;
	}
};