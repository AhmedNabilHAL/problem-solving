#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <unordered_set>
typedef long long ll;

using namespace std;
const int N = 2e5 + 5, M = 3e5 + 5, OO = 0x3f3f3f3f;
const double EPS = 1e-8;

//#define x real()
//#define y imag()
//complex<double> operator/(complex<ll> &a, double len){
//	complex<double> ret(a.x / len, a.y / len);
//	return ret;
//}
//complex<double> operator*(complex<ll> &a, double len){
//	complex<double> ret(a.x * len, a.y * len);
//	return ret;
//}
//complex<double> point(double r, double i){
//	complex<double> ret(r, i);
//	return ret;
//}
//#define angle(a)	atan2(a.imag(), a.real())
//#define vec(a, b)	(b-a)
//#define length(a)	hypot(a.imag(), a.real())
//#define normalize(a)	(a) / length(a)
//#define dp(a, b) (conj(a)*b).x
//#define cp(a, b) (conj(a)*b).y
//#define lengthsqr(a) dp(a, a)
//#define rotate0(p, theta) ((p) * exp(point(0, theta)))
//#define rotateA(p, theta, about) (rotate0(vec(about, p), theta) + about)
//#define reflect0(v,m) (conj(v/m)*m)
//#define reflectA(v,m,about) (reflect0(vec(about, v), m) + about)
int dcmp(double d1, double d2){
	return (fabs(d1 - d2) <= EPS) ? 0 : (d1 < d2) ? -1 : 1;
}
int m, n, T, a, b, t; deque<int> t0, t1;

bool iseasy[N];
bool cansolve(int questions){
	int solved = 0; int s = 0;
	deque<int> t01 = t0;
	deque<int> t11 = t1;
	while (solved < questions || (!t11.empty() ? t11.front() <= s : 0) || (!t01.empty() ? t01.front() <= s : 0)){
		if (!t11.empty() && t11.front() <= s){
			if (b > T - s) return 0;
			solved++;
			s += b;
			
			t11.pop_front();
		}
		else if (!t01.empty()){
			if (a > T - s) return 0;
			solved++;
			s += a;
			
			t01.pop_front();
		}
		else if (!t11.empty()){
			if (b > T - s) return 0;
			solved++;
			s += b;
			
			t11.pop_front();
		}
		else return 0;
	}

	return 1;
}
int binarySearch(){
	int le = 0, mid, ri = n;
	while (le < ri){
		mid = (le + ri + 1) / 2;
		if (cansolve(mid)) le = mid;
		else ri = mid - 1;
	}
	return le;
}
int main(){
	scanf("%d", &m);
	while (m--){
		t0.clear(); t1.clear();
		scanf("%d%d%d%d", &n, &T, &a, &b);
		for (int i = 0; i < n; ++i) { int x; scanf("%d", &x); iseasy[i] = !x; }
		for (int i = 0; i < n; ++i) { scanf("%d", &t);  if (iseasy[i]) t0.push_back(t); else t1.push_back(t); }
		sort(t0.begin(), t0.end()); sort(t1.begin(), t1.end());
		printf("%d\n", binarySearch());
		
	}
	return 0;
}