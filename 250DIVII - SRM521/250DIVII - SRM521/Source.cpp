#include <iostream>
#include <vector>
#include <string>

using namespace std;

int restOfReds(string &row, int s, int ln);
bool isCorrect(string &row);
int addAns(int ans, int new_ans);

class RedAndGreen {
public:

	int minPaints(string row)
	{
		
		int ln = row.length();

		int i = 0;
		int cost = 0;
		int ans = -1;
		if (isCorrect(row))
			return 0;
		char temp;
		
		while (i < ln)
		{
			int greens = 0; int reds = 0; temp = row[i];
			while (row[i] == temp && i < ln)
			{
				if (row[i] == 'R')
					reds++;
				else
					greens++;
				temp = row[i];
				i++;
			}
			temp = row[i];
			while (row[i] == temp && i < ln)
			{
				if (row[i] == 'R')
					reds++;
				else
					greens++;
				temp = row[i];
				i++;
			}
			int rest = restOfReds(row, i, ln);
			rest = (row[i] == 'R') ? rest : reds + rest;
			ans = addAns(ans, cost + rest);
			if (greens > rest)
			{
				if (!(i >= ln && row[i - 1] == 'G'))
					cost += rest;
				break;
			}
			else if (!(i >= ln && row[i - 1] == 'G'))
				cost += greens;
		}
		return (cost < ans) ? cost : ans;
	}
};

int restOfReds(string &row, int s, int ln)
{
	int reds = 0;
	for (int i = s; i < ln; i++)
	{
		if (row[i] == 'R')
			reds++;
	}
	return reds;
}

bool isCorrect(string &row)
{
	int ln = row.length();
	int i = 0;
	while (row[i] == 'R')
	{
		if (i >= ln - 1)
			return true;
		i++;
	}
	while (row[i] != 'R')
	{
		if (i >= ln - 1)
			return true;
		i++;
	}
	return false;
}

int addAns(int ans, int new_ans)
{
	if (ans == -1)
		return new_ans;
	else if (new_ans < ans)
		return new_ans;
	else
		return ans;
}
int main()
{
	RedAndGreen x;
	cout << x.minPaints("RGRRRRRRGRRRRRRGRRRRRRRRRRGRRGRRRRRRRGRRRRRRRRRRRG") << endl;
}