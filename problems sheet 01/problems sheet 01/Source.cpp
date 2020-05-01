#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

// ==================
// void problem_01();
// void problem_02();
// void problem_03();
// ==================


const int N = 1e5 + 5;

int main()
{
	
	return 0;
}
void problem_01(){
	int n; 
	cin >> n;
	string s;
	cin >> s;
	string ans = "";
	for (int i = n - 1; i >= 0; i--){
		char ch = s[i];
		ans.insert(ans.begin() + (int)ans.size() / 2, ch);
	}
	cout << ans << endl;
}
void problem_02(){
	int dp[N];
	int h[N];
	int n;
	scanf("%d", &n);
	int b = 0;
	int ans = 1;
	if (n){
		dp[0] = 1;
		scanf("%d", h);
	}
	for (int i = 1; i < n; i++){
		scanf("%d", h + i);
		if (h[i - 1] > h[i]){
			dp[i] = 1;
			dp[b]++;
		}
		else if (h[i - 1] == h[i]){
			dp[i] = dp[i - 1] + 1;
			dp[b]++;
		}
		else{
			dp[i] = dp[i - 1] + 1;
			b = i;
		}
		ans = (ans > dp[b]) ? ans : dp[b];
	}
	printf("%d\n", ans);
}
void problem_03(){
	vector<int> c;
	int a, n; scanf("%d%d", &n, &a);

	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		c.push_back(x);
	}
	int ans = 0;
	for (int i = a - 1, j = a - 1; i < n || j >= 0; ++i, --j){
		if ((i > n - 1 && c[j]) || (j < 0 && c[i]))
			ans++;
		else if (c[i] && c[j])
		if (i == a - 1)
			ans++;
		else ans += 2;
	}
	printf("%d\n", ans);
}