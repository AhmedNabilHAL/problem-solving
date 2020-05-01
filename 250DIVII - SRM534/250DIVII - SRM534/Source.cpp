#include <iostream>
#include <vector>

using namespace std;

class EllysDirectoryListing {
public:

	vector <string> getFiles(vector <string> files) {
		
		int ln = files.size();
		int j = ln - 1;
		int k = 0;
		while (k < 2)
		{	
			
			//search for . or .. then replace it with j
			for (int i = 0; i <= ln - 3; i++)
			{
				if (files[i] == "." || files[i] == "..")
				{
					string temp = files[i];
					files[i] = files[j];
					files[j] = temp;
					j--;
				}
			}
			k++;
		}
		return files;
		
	}
};

int main()
{
	vector <string> vect{ "No", "..", "Zaphod", ".", "Just", "very", "very...", "Improbable" };
	EllysDirectoryListing x;
	x.getFiles(vect);
}