#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mySearch(vector <int> &ratings, int start, int end, int);

class SRMRoomAssignmentPhase {
public:

	int countCompetitors(vector <int> ratings, int K)
	{

		int ln = ratings.size();
		if (K > ln)
			return 0;
		int index = 0;
		int my_rating = ratings[index];
		sort(ratings.begin(), ratings.end());
		index = mySearch(ratings, 0, ln, my_rating);
		int i = 0;
		ln -= K;
		while (true)
		{
			if (index + 1 > ln)
				return i;
			i++;
			ln -= K;
		}
		return 0;
	}
};

int mySearch(vector <int> &ratings, int start, int end, int r)
{
	if (end < start)
		return 0;
	int mid = (start + end) / 2;
	if (r == ratings[mid])
		return mid;
	else if (r > ratings[mid])
		return mySearch(ratings, mid, end, r);
	else if (r < ratings[mid])
		return mySearch(ratings, start, mid, r);
	return 0;

}