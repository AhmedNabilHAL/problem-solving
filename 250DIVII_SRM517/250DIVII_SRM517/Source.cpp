#include <iostream>
#include <vector>

using namespace std;

int checkRow(string row, int ln);


class MonochromaticBoard {
public:

	int theMin(vector <string> board)
	{
		int rows = board.size();
		int cols = board[0].length();

		int ans = 0;


		int blues = 0;
		for (int i = 0; i < rows; i++)
		{
			int x = checkRow(board[i], cols);
			if (x == cols)
				ans++;
			else
				blues = x;
		}
		ans += blues;
		return ans;

	}
};

int main()
{
	vector <string> table { "WBWBW",
		"BBBBB",
		"WBWBW",
		"WBWBW" };
	MonochromaticBoard x;
	cout << x.theMin(table) << endl;
}
int checkRow(string row, int ln)
{
	int i = 0;
	int blues = 0;
	for (int i = 0; i < ln; i++)
	{
		if (row[i] == 'B')
			blues++;

	}
	return blues;
}
