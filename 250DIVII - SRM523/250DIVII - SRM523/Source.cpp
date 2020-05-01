#include <iostream>
#include <string>
#include <vector>
using namespace std;



class AlphabetPath {
public:

	string doesItExist(vector <string> letterMaze)
	{
		string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int rows = letterMaze.size() - 1;
		int cols = letterMaze[0].length() - 1;
		int i = 0; int j = 0; int k = 1;
		bool found = false;
		for (i = 0; i < rows + 1; i++)
		{
			for (j = 0; j < cols + 1; j++)
			{
				if (letterMaze[i][j] == 'A')
				{
					found = true;
					break;
				}

			}
			if (found)
				break;
		}
		
		while (k < 26)
		{
			if (i < rows && letterMaze[i + 1][j] == alpha[k])
				i++;
			else if (j < cols && letterMaze[i][j + 1] == alpha[k])
				j++;
			else if (i > 0 && letterMaze[i - 1][j] == alpha[k])
				i--;
			else if (j > 0 && letterMaze[i][j - 1] == alpha[k])
				j--;
			else
				return "NO";
			k++;

		}
		return "YES";
	}
};

int main()
{
	AlphabetPath x;
	vector <string> mat{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	cout << x.doesItExist(mat);
}