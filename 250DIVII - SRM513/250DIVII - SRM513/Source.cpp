#include <iostream>
#include <vector>

using namespace std;
class TrainingCamp {
public:

	vector <string> determineSolvers(vector <string> attendance, vector <string> problemTopics)
	{
		bool solved;
		int students = attendance.size();
		int topics = problemTopics.size();
		int ln = attendance[0].length();
		// declare an empty vector
		vector <string> ans;
		// for each student
		for (int i = 0; i < students; i++)
		{
			// append an empty string to ans vector
			ans.push_back("");
			//iterate over topics
			for (int j = 0; j < topics; j++)
			{
				solved = true;
				//iterate over his attendance
				for (int k = 0; k < ln; k++)
					// if a att[i] == - and if topics[i] == X then append - else append X
				if (attendance[i][k] == '-' && problemTopics[j][k] == 'X')
					solved = false;
				if (solved)
					ans[i].append("X");
				else
					ans[i].append("-");
			}
		}
		return ans;

	}
};

int main()
{

	TrainingCamp x;
	vector <string> vect1{ "XXX", "XXX", "XX-" };
	vector <string> vect2{ "---", "XXX", "-XX", "XX-" };
	vector <string> ans;
	ans = x.determineSolvers(vect1, vect2);

	return 0;
}