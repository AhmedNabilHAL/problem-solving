#include <iostream>
#include <vector>

using namespace std;

class FoxAndIntegers {
public:

	vector <int> get(int AminusB, int BminusC, int AplusB, int BplusC) {
		// AmB = A - B
		// BmC = B - C
		// ApB = A + B
		// BpC = B + C
		int A = (AminusB + AplusB) / 2;
		int B = AplusB - A;
		int C = B - BminusC;
		vector <int> ans;
		if (B + C != BplusC || A + B != AplusB || A - B != AminusB || B - C != BminusC)
			return ans;
		ans.push_back(A);
		ans.push_back(B);
		ans.push_back(C);
		return ans;
	}
};