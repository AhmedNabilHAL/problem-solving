#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int> &arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	vector <int> L, R;

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L.push_back(arr[l + i]);
	for (j = 0; j < n2; j++)
		R.push_back(arr[m + 1 + j]);

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(vector <int> &arr, int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

class UnsortedSequence {
public:

	vector <int> getUnsorted(vector <int> s)
	{
		int ln = s.size();
		bool diff = false;

		mergeSort(s, 0, ln - 1);
		for (int i = ln - 1; i >= 1; i--)
		{
			if (s[i] != s[i - 1])
			{
				diff = true;
				int temp = s[i - 1];
				s[i - 1] = s[i];
				s[i] = temp;
				break;
			}
		}
		if (!diff)
		{
			vector<int> vect;
			return vect;
		}
		return s;
	}
};