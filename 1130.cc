#include <bits/stdc++.h>
using namespace std;
 
constexpr int maxn = 200010;
int dp[maxn][2];
vector<int> G[maxn];

// 1 -> can take
// 0 -> cant take

void dfs(int u, int p) {
	int s = 0;
	for (int v: G[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] += dp[v][1];
	}
	dp[u][1] = dp[u][0];

	for (int v: G[u]) {
		if (v == p) continue;

		dp[u][1] = max(dp[u][1], dp[u][0] - dp[v][1] + dp[v][0] + 1);
	}
}
 
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	cout << dp[1][1] << "\n";
	return 0;
}