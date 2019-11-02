#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5005;
int dp[maxn][maxn];
string a, b;

int solve(int i, int j) {
	int n = a.size();
	int m = b.size();

	if (i == n && j == m) return 0;
	else if (i == n) return (m - j);
	else if (j == m) return (n - i);
	else if (dp[i][j] != -1) return dp[i][j];

	int ret = min(1 + solve(i + 1, j), 1 + solve(i, j + 1));
	ret = min(ret, (a[i] != b[j]) + solve(i + 1, j + 1));

	return (dp[i][j] = ret);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> a >> b;
	cout << solve(0, 0) << "\n";
	return 0;
}