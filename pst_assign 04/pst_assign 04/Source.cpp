#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

using namespace  std;
const int N = 5e5 + 5, M = 1000 + 5;
long long MIN = -2e9;
long long n, k, T; pair<pair<long long, long long>, long long> pts[M]; long long x_pos[M];

bool search_y(long long ln, long long left, long long right){
	long long freq_y[101] = { 0 }; long long l = -1, lastcovered = MIN;long long zeroes = k;
	long long i = 0;
	while (i < n && l < n){
		
		if (pts[i].first.second < left || pts[i].first.second > right){
			i++;
			continue;
		}
		if (pts[i].first.first > lastcovered){
			if (!zeroes) return 1;
			// update boundry
			if (l != -1) {
				freq_y[pts[l].second]--;
				if (freq_y[pts[l].second] == 0) zeroes++;
			}
			do{
				l++;
			} while (pts[l].first.second < left || pts[l].first.second > right);
			lastcovered = pts[l].first.first + ln;
		}
		else{
			freq_y[pts[i].second]++;
			if (freq_y[pts[i].second] == 1) zeroes--;
			i++;
		}
	}
	if (!zeroes) return 1;
	return 0;
}

bool isPossibleLn(long long ln){
	for (long long i = 0; i < n; ++i){
		if (search_y(ln, x_pos[i], x_pos[i] + ln))
			return 1;
	}
	return 0;
}
long long binarySearch(){
	long long lo = 1, mid, hi = 4e9;
	while (lo < hi){
		mid = (lo + hi) / 2;
		if (isPossibleLn(mid)) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main(){
	scanf("%lld", &T);
	while (T--){
		scanf("%lld", &n);
		scanf("%lld", &k);
		for (long long i = 0; i < n; ++i) {
			long long x, y, z;
			scanf("%lld", &x);
			scanf("%lld", &y);
			scanf("%lld", &z);
			pts[i].first.first = y; pts[i].first.second = x; pts[i].second = z;
			x_pos[i] = x;
		}
		sort(pts, pts + n);
		sort(x_pos, x_pos + n);
		
		printf("%lld\n", binarySearch());
	}
}