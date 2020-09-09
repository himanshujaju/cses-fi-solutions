#include <bits/stdc++.h>
using namespace std;
 
constexpr int maxn = 666;
double dp[maxn];
 
int main() {
	int n, a, b;
	cin >> n >> a >> b;
	dp[0] = 1.0;

	for (int i = 1; i <= n; i++) {
		for (int sum = (6 * i); sum >= 0; sum--) {
			double val = 0.0;
			for (int d = 1; d <= 6; d++) {
				if (sum - d < 0) break;

				val += dp[sum - d];
			}
			dp[sum] = val / 6.0;
		}
	}

	double ans = 0.0;
	for (int i = a; i <= b; i++) {
		ans += dp[i];
	}
	
	printf("%.6f\n", ans);
	return 0;
}
