#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100001;
constexpr int maxm = 101;
constexpr int mod = 1000000007;

int _add(int a, int b){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int dp[maxn][maxm];
int arr[maxn];
int n, m;

int solve(int a, int b) {
	if (b < 1 || b > m) return 0;
	if (arr[a] && arr[a] != b) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	if (a == 1) return 1;

	int ret = _add(solve(a - 1, b - 1), solve(a - 1, b + 1));
	ret = _add(ret, solve(a - 1, b));
	return (dp[a][b] = ret);
}
 
int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	int ans = 0;
	for (int v = 1; v <= m; v++)
		ans = _add(ans, solve(n, v));

	cout << ans << "\n";
	return 0;
}