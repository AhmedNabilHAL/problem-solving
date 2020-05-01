#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class LeftOrRight {
public:

	int maxDistance(string program) {
		int moves = 0;
		int max = 0;
		
		for (int i = 0; i < program.length(); i++)
		{
			if (program[i] == 'L')
				moves++;
			else if (program[i] == 'R')
				moves--;
			else
				moves++;
			max = (abs(moves) > max) ? abs(moves) : max;
		}
		moves = 0;
		for (int i = 0; i < program.length(); i++)
		{
			if (program[i] == 'L')
				moves++;
			else if (program[i] == 'R')
				moves--;
			else
				moves--;
			max = (abs(moves) > max) ? abs(moves) : max;
		}
		return max;
	}
};
int main()
{
	LeftOrRight x;
	cout << x.maxDistance("R???L")<< endl;
}