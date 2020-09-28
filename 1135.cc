#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200000;
constexpr int maxlog = 20;
int par[maxlog][maxn + 1];
int depth[maxn + 1];
vector<int> edges[maxn + 1];

bool IsSet(int mask, int id) {
	return ((mask >> id) & 1);
}

void dfs(int u, int p = 0, int dep = 0) {
	depth[u] = dep;
	par[0][u] = p;

	for (int v: edges[u]) {
		if (v == p) continue;
		dfs(v, u, dep + 1);
	}
}

int lca(int u, int v) {
	if (depth[v] < depth[u])
		swap(u, v);

	int diff = depth[v] - depth[u];
	for (int i = 0; i < maxlog; i++) {
		if (!IsSet(diff, i)) continue;
		v = par[i][v];
		diff -= (1 << i);
	}

	if (u == v) return u;

	for (int i = maxlog - 1; i >= 0; i--) {
		if (par[i][u] != par[i][v]) {
			u = par[i][u];
			v = par[i][v];
		}
	}

	return par[0][u];
}

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(1);

	for (int i = 1; i < maxlog; i++) {
		for (int j = 1; j <= n; j++) {
			int v = par[i - 1][j];
			par[i][j] = par[i - 1][v];
		}
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		int l = lca(u, v);
		int dist = depth[u] + depth[v] - 2 * depth[l];
		cout << dist << "\n";
	}
	return 0;
}
