#include <iostream>
#include <string>

using namespace std;

class KingXNewBaby {
public:

	string isValid(string name) {
		int ln = name.length();
		if (ln != 8)
			return "NO";
		int vowels = 0;
		char ch = 'a';
		for (int i = 0; i < ln; i++)
		{
			
			if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
			{
				if (ch != name[i] && vowels != 0)
					return "NO";
				vowels++;
				ch = name[i];
			}
			if (vowels > 2)
				return "NO";
		}
		if (vowels < 2)
			return "NO";
		return "YES";
	}
};

int main()
{
	KingXNewBaby x;
	cout << x.isValid("jkstdfuu") << endl;
}