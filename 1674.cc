#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200010;
vector<int> G[maxn];
int ans[maxn];

void dfs(int u) {
	ans[u] = 1;
	for (int v: G[u]) {
		dfs(v);
		ans[u] += ans[v];
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		G[p].push_back(i);
	}

	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << ans[i] - 1 << " ";
	}
	return 0;
}
