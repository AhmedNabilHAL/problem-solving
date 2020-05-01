#include <iostream>
#include <vector>
#include <string>

using namespace std;

string WEEKDAYS[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
class WhichDay {
public:

	string getDay(vector <string> notOnThisDay)
	{

		bool d[7] = { false };
		int ln = 6;
		for (int i = 0; i < ln; i++)
		{
			if (notOnThisDay[i] == "Sunday")
				d[0] = true;
			else if (notOnThisDay[i] == "Monday")
				d[1] = true;
			else if (notOnThisDay[i] == "Tuesday")
				d[2] = true;
			else if (notOnThisDay[i] == "Wednesday")
				d[3] = true;
			else if (notOnThisDay[i] == "Thursday")
				d[4] = true;
			else if (notOnThisDay[i] == "Friday")
				d[5] = true;
			else if (notOnThisDay[i] == "Saturday")
				d[6] = true;
		}
		for (int i = 0; i < 7; i++)
		{
			if (!d[i])
				return WEEKDAYS[i];
		}
		return WEEKDAYS[2];

	}
};

int main()
{
	WhichDay x;
	vector <string> vect{ "Sunday", "Friday", "Tuesday", "Wednesday", "Monday", "Saturday" };
	string str = x.getDay(vect);
	cout << str << endl;
	return 0;
}