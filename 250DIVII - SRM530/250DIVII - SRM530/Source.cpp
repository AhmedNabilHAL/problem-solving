#include <iostream>
#include <vector>

using namespace std;

int findMoves(vector <int> T, vector <int> S);

class GogoXBallsAndBinsEasy {
public:

	int solve(vector <int> T)
	{
		int ln = T.size();
		vector <int> S;
		for (int i = ln - 1; i >= 0; i--)
		{
			S.push_back(T[i]);
		}
		return findMoves(T, S);
	}
};

int findMoves(vector <int> T, vector <int> S)
{
	int moves = 0;
	for (int i = 0; i < S.size(); i++)
	{
		moves = (S[i] > T[i]) ? moves + (S[i] - T[i]): moves;
	}
	return moves;
}