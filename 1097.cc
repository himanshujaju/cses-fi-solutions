#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5005;
long long arr[maxn];
long long pre[maxn];
long long dp[maxn][maxn];

long long solve(int l, int r) {
	if (l == r) return arr[l];
	else if (dp[l][r] != -1) return dp[l][r];

	long long ret = pre[r] - pre[l - 1] - min(solve(l + 1, r), solve(l, r - 1));
	return (dp[l][r] = ret);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(1, n) << "\n";
	return 0;
}