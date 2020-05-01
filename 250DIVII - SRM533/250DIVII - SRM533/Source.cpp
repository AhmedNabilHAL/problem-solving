#include <iostream>
#include <string>
using namespace std;

class PikachuEasy {
public:

	string check(string word) {
		bool ans = true;
		int ln = word.length();
		string substring = "";
		int sub_ln = 0;
		for (int i = 0; i < ln; i++)
		{
			substring += word[i];
			sub_ln++;
			
			if (sub_ln == 2 && (substring == "pi" || substring == "ka"))
			{
				substring = "";
				sub_ln = 0;
			}
			else if (sub_ln <= 2 && i != ln - 1)
				continue;
			else if (sub_ln == 3 && substring == "chu")
			{
					substring = "";
					sub_ln = 0;
			}
			else
			{
				ans = false;
				break;
			}

		}
		if (ans)
			return "YES";
		return "NO";

	}
};

int main()
{
	PikachuEasy x;
	cout << x.check("pichukd") << endl;
}