#include <iostream>

using namespace std;


class NetworkXZeroOne {
public:

	string reconstruct(string message)
	{
		string ans1 = "", ans2 = "";
		bool ans2Bool = true;
		for (int i = 0; i < message.length(); i++)
		{
			if (i % 2)
			{
				ans1.append("x");
				ans2.append("o");
				if (message[i] == 'x')
					ans2Bool = false;
			}
			else
			{
				ans1.append("o");
				ans2.append("x");
				if (message[i] == 'o')
					ans2Bool = false;
			}
		}
		if (ans2Bool)
			return ans2;
		return ans1;
	}
};