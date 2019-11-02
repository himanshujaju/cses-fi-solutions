#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100010;

int color[maxn];
vector<int> G[maxn];

bool dfs(int u, int p) {
	for (int v: G[u]) {
		if (v == p) continue;
		if (color[v] == (3 - color[u])) continue;
		if (color[v]) return false;

		color[v] = 3 - color[u];
		if (!dfs(v, u)) return false;
	}

	return true;
}
 
int main() {
	int n, m;
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	bool ok = true;
	for (int i = 1; i <= n && ok; i++) {
		if (color[i]) continue;
		color[i] = 1;
		ok &= dfs(i, 0);
	}

	if (!ok) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for (int i = 1; i <= n; i++)
		cout << color[i] << " ";
	return 0;
}