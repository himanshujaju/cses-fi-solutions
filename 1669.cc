#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100010;
int depth[maxn], par[maxn];
vector<int> G[maxn];
bool done = false;

void output(int starting, int ending) {
	vector<int> arr;
	arr.push_back(starting);

	while(ending != starting) {
		arr.push_back(ending);
		ending = par[ending];
	}
	arr.push_back(starting);

	cout << arr.size() << "\n";
	for (int v: arr)
		cout << v << " ";
	cout << "\n";
}

void dfs(int u, int p, int d) {
	if (done) return;

	depth[u] = d;
	par[u] = p;
	for (int v: G[u]) {
		if (v == p) continue;
		if (depth[v] == 0)
			dfs(v, u, d + 1);
		else {
			done = true;
			output(v, u);
		}
		
		if (done) break;
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n && !done; i++) {
		if (depth[i] == 0)
			dfs(i, 0, 1);
	}

	if (!done)
		cout << "IMPOSSIBLE\n";
	return 0;
}