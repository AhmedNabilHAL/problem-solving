#include <iostream>
#include <vector>

using namespace std;

class ContestWinner {
public:

	int getWinner(vector <int> events)
	{
		int arr[1000001] = { 0 };
		int time[1000001] = { 0 };
		// iterate over events
		for (int i = 0; i < events.size(); i++)
		{
			if (events[i] >= 1000001)
				return -1;
			// arr[events[i]]++
			arr[events[i]]++;

			time[events[i]] = i + 1;
		}
		// iterate over contestents
		int max = 0;
		int ans = events[0];
		for (int i = 0; i < events.size(); i++)
		{
			// if arr[contestents[i]] > max
			if (arr[events[i]] >= max)
			{
				
				if (arr[events[i]] != max || time[events[i]] <= time[ans])
				{
					// max = arr[contestents[i]]
					max = arr[events[i]];
					// ans = contestents[i]
					ans = events[i];
				}
			}
		}
		//return ans
		return ans;
	}

};
int main()
{
	vector <int> vect {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	ContestWinner x;
	cout << x.getWinner(vect) << endl;
	return 0;
}

