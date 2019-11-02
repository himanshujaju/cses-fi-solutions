#include <bits/stdc++.h>
using namespace std;
 
constexpr int maxn = 100010;
int dp[maxn];
vector<int> G[maxn];
 
int go(int u) {
	if (dp[u] != -1) return dp[u];
	dp[u] = -maxn;
	for (int v: G[u])
		dp[u] = max(dp[u], 1 + go(v));
	return dp[u];
}

void trace(int u) {
	cout << u << " ";
	if (dp[u] == 0) return;

	for (int v: G[u]) {
		if (dp[u] == dp[v] + 1) {
			trace(v);
			return;
		}
	}
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
	dp[n] = 0;
	int ans = go(1);
	if (ans < 1) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << ans + 1 << "\n";
		trace(1);
	}
	return 0;
}