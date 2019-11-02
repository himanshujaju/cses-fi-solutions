#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200000;
vector<int> G[maxn];
int dist[maxn], parent[maxn];
 
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dist[i] = maxn, parent[i] = -1;

	while (m--) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	queue<int> bfs;
	bfs.push(1);
	parent[1] = 1;
	dist[1] = 0;

	while(!bfs.empty()) {
		int ele = bfs.front();
		bfs.pop();
		int d = dist[ele] + 1;

		for (int v: G[ele]) {
			if (d >= dist[v]) continue;

			dist[v] = d;
			parent[v] = ele;
			bfs.push(v);
		}
	}
	if (dist[n] > n) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vector<int> arr;
	while(n > 1) {
		arr.push_back(n);
		n = parent[n];
	}
	arr.push_back(1);
	reverse(arr.begin(), arr.end());
	cout << arr.size() << "\n";
	for (int v: arr)
		cout << v << " ";
	cout << "\n";
	return 0;
}