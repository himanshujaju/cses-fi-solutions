#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 505;
int dp[maxn][maxn];

int solve(int a, int b) {
	if (a == b) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	int ret = INT_MAX;
	for (int i = 1; i < a; i++)
		ret = min(ret, solve(i, b) + solve(a - i, b));
	for (int i = 1; i < b; i++)
		ret = min(ret, solve(a, i) + solve(a, b - i));
	ret++;
	return (dp[a][b] = ret);
}
 
int main() {
	memset(dp, -1, sizeof(dp));
	int a, b;
	cin >> a >> b;
	cout << solve(a, b) << "\n";
	return 0;
}