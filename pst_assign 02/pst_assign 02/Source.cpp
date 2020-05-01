#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
const int N = 2e5 + 5;

int main(){
	char s[N]; scanf("%s", s);
	int freq[N] = {};
	int n = strlen(s);
	int m; scanf("%d", &m);
	while (m--){
		int a; scanf("%d", &a);
		freq[a - 1]++;
	}
	for (int i = 1; i < n / 2; i++){
		freq[i] += freq[i - 1];
	}
	for (int i = 0; i < n / 2; ++i){
		if (freq[i] % 2)
			swap(s[i], s[n - i - 1]);
	}
	printf("%s\n", s);
	return 0;
}

void problem_A(){
	int freq[27] = {};
	char sent[101];
	int n;
	scanf("%d", &n);
	scanf("%s", sent);
	while (n--){
		if (isupper(sent[n]))
			sent[n] = tolower(sent[n]);
		freq[sent[n] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	if (!freq[i]){
		printf("NO\n");
		return;
	}
	printf("YES\n");
}
void problem_B(){
	int n = 0, q = 0, l = 0, r = 0, sum = 0, x = 0;
	int sums[100000] = {};
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		sums[i] = sum + x;
		sum += x;
	}
	scanf("%d", &q);
	while (q--){
		scanf("%d%d", &l, &r);
		printf("%d\n", ((r) ? sums[r] : 0) - ((l) ? sums[l - 1] : 0));
	}
}
void problem_C(){
	int t;
	scanf("%d", &t);
	while (t--){
		unordered_map<int, int> freq;
		freq[0] = 0;
		int n;
		scanf("%d", &n);
		while (n--){
			int x;
			scanf("%d", &x);
			freq[x]++;
		}
		int ans = 0;
		for (auto it = freq.begin(); it != freq.end(); it++){
			if (it->first){
				int r = freq[it->first + 1];
				int l = freq[it->first - 1];
				int y = (r > l) ? r : l;
				int m = it->second;
				ans = (m + y > ans) ? m + y : ans;
			}
		}
		printf("%d\n", ans);
	}
}
void problem_D(){
	int sums[N] = {};
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int x; scanf("%d", &x);
		sums[i] += ((i) ? sums[i - 1] : 0) + x;
	}
	int q; scanf("%d", &q);
	while (q--){
		int x; scanf("%d", &x);
		auto it = lower_bound(sums, sums + n, x);
		printf("%d\n", it - sums + 1);
	}
}
void problem_E(){
	int sums[N] = {};
	char s[N];
	scanf("%s", s);
	int i = 0;
	while (s[i]){
		sums[i + 1] = sums[i] + ((s[i] == s[i + 1]) ? 1 : 0);
		++i;
	}
	int q; scanf("%d", &q);
	while (q--){
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", sums[r - 1] - sums[l - 1]);
	}
}