#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100010;
constexpr int mod = 1000000007;
int dp[maxn];
vector<int> G[maxn];

int _add(int a, int b){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int go(int u) {
	if (dp[u] != -1) return dp[u];
	dp[u] = 0;
	for (int v: G[u])
		dp[u] = _add(dp[u], go(v));
	return dp[u];
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	dp[n] = 1;

	cout << go(1) << "\n";
	return 0;
}