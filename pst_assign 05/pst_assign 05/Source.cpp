# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;
long long T, n, first, dzy, fox;
deque<long long> dq;
int main(){
	scanf("%lld", &T);
	while (T--){
		dq.clear();
		dzy = 0;
		fox = 0;
		scanf("%lld", &n);
		bool b = 1;
		for (int i = 0; i < n; ++i){
			long long x;
			scanf("%lld", &x);
			if (b)
				dzy += x;
			else
				fox += x;
			dq.push_back(x);
			b = !b;
		}
		if (n % 2 == 0){
			printf("%lld\n", (dzy > fox) ? dzy : fox);
			continue;
		}
		long long ans = dzy;
		for (int i = 0; i < n - 1; ++i){
			long long temp = dzy;
			dzy = fox + dq[0];
			fox = temp - dq[0];
			dq.push_back(dq[0]);
			dq.pop_front();
			ans = (dzy > ans) ? dzy : ans;
		}
		printf("%lld\n", ans);
	}
	return 0;
}