#include <iostream>
#include <string>

using namespace std;

class ColorfulBricks {
public:

	int countLayouts(string bricks)
	{
		char ch1 = bricks[0];
		char ch2 = bricks[0];
		int n = 1;
		for (int i = 1; i < bricks.length(); i++)
		{
			if (ch1 != bricks[i] && n == 1)
			{
				ch2 = bricks[i];
				n++;
				continue;
			}
			else if (ch1 != bricks[i] && ch2 != bricks[i])
				return 0;
		}
		return n;
	}
};
int main()
{
	ColorfulBricks x;
	string bricks = "AABB";
	cout << x.countLayouts(bricks) << endl; // 2
	bricks = "AA";
	cout << x.countLayouts(bricks) << endl;//1
	bricks = "AABBC";
	cout << x.countLayouts(bricks) << endl;//0

}