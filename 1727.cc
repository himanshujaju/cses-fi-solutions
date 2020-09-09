#include <bits/stdc++.h>
using namespace std;

long double GetProb(long double val, int times) {
	long double ret = 1;
	for (int i = 1; i <= times; i++)
		ret *= val;
	return ret;
}
 
int main() {
	int n, x;
	cin >> n >> x;

	long double ans = 0.0;
	for (int mx = 1; mx <= x; mx++) {
		long double curr = GetProb((1.0 * mx) / x, n) - GetProb((1.0 * (mx - 1)) / x, n);
		ans += mx * curr;
	}

	printf("%.6Lf\n", ans);
	return 0;
}
