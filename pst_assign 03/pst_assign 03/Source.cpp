#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <set>
using namespace std;

int n, k;
pair<int, int> a[1000];
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].first);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i].second);
	int cookies = INT_MAX;
	for (int i = 0; i < n; ++i){
		int c = a[i].second / a[i].first;
		cookies = (c < cookies) ? c : cookies;
	}
	for (int i = 0; i < n; ++i){
		a[i].second -= cookies * a[i].first;
	}
	
	while (true){
		int need = 0;
		for (int i = 0; i < n; ++i){
			int y = a[i].first - a[i].second;
			if (y > 0){
				need += y;
				a[i].second += y;
			}
		}
		if (k >= need){
			k -= need;
			for (int i = 0; i < n; ++i){
				a[i].second -= a[i].first;
			}
			cookies++;
		}
		else break;
	}
	printf("%d\n", cookies);
	return 0;
}
void problem_A(){
	int t, n, p, bars[20];
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &p);
		bool isprinted = false;
		for (int i = 0; i < p; i++){
			scanf("%d", bars + i);
		}
		int perm = 1 << p;
		for (int i = 0; i < perm; ++i){
			int sum = 0;
			for (int j = 0; j < p; j++){
				if ((i >> j) & 1)
					sum += bars[j];
			}
			if (sum == n){
				printf("YES\n");
				isprinted = true;
				break;
			}
		}
		if (!isprinted)
			printf("NO\n");
	}
}
void problem_B(){
	int n, t, mins[20];
	vector<int> tracks[1 << 20];
	while (cin >> n){
		scanf("%d", &t);
		for (int i = 0; i < t; i++){
			scanf("%d", mins + i);
		}
		int perm = 1 << t;
		for (int i = 0; i < perm; ++i)
			tracks[i].clear();
		int ans = 0;
		int v = 0;
		for (int i = 0; i < perm; ++i){
			int sum = 0;

			for (int j = 0; j < t; j++){
				if ((i >> j) & 1){
					tracks[i].push_back(mins[j]);
					sum += mins[j];
				}
			}
			if (sum >= ans && sum <= n){
				ans = sum;
				v = i;
			}
		}
		for (int i = 0; i < tracks[v].size(); ++i)
			printf("%d ", tracks[v][i]);
		printf("sum:%d\n", ans);
	}
}
void problem_C(){
	int n, l, r, x, c[15];
	set<int> st;
	scanf("%d%d%d%d", &n, &l, &r, &x);
	int perm = 1 << n;
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i);
	int ans = 0;
	for (int i = 0; i < perm; ++i){
		int sum = 0;
		for (int j = 0; j < n; j++){
			if (i&(1 << j)){
				sum += c[j];
				st.insert(c[j]);
			}
		}
		if (st.size() > 1 && sum >= l && sum <= r && (*st.rbegin() - *st.begin()) >= x)
			ans++;
		st.clear();
	}
	printf("%d\n", ans);
}
void problem_D(){
	int n; scanf("%d", &n);
	int ans = 0;
	while (n){
		if (n & 1)
			ans++;
		n = n >> 1;
	}
	printf("%d\n", ans);
}