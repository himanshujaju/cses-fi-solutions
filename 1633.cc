#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1000010;
constexpr int mod = 1000000007;

int dp[maxn];

int _add(int a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = 1; j <= min(i, 6); j++)
			dp[i] = _add(dp[i], dp[i - j]);
	}
	cout << dp[n] << "\n";
	return 0;
}
