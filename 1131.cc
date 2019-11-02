#include <bits/stdc++.h>
using namespace std;
 
constexpr int maxn = 200010;
vector<int> G[maxn];

struct subtree {
	int longest_chain;
	int ans;

	subtree() : longest_chain(0), ans(0) {}
};

subtree dfs(int u, int p) {
	subtree temp;

	int max_len = 0;
	for (int v: G[u]) {
		if (v == p) continue;
		subtree tree_v = dfs(v, u);
		temp.ans = max(temp.ans, tree_v.ans);
		temp.ans = max(temp.ans, max_len + tree_v.longest_chain);
		max_len = max(max_len, tree_v.longest_chain);
	}

	temp.longest_chain = max_len + 1;
	return temp;
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
	subtree tree = dfs(1, 0);
	cout << tree.ans << "\n";
	return 0;
}