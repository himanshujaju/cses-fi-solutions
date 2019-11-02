#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = (1LL << 60);
constexpr int maxn = 100010;
vector<pair<int,int>> G[maxn];
long long dist[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dist[i] = inf;
	}
	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back({v, c});
	}

	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
	dist[1] = 0;
	pq.push({dist[1], 1});

	while(!pq.empty()) {
		auto ele = pq.top();
		pq.pop();

		if (dist[ele.second] != ele.first) continue;

		for (auto e: G[ele.second]) {
			long long c_dist = e.second + ele.first;
			if (c_dist >= dist[e.first]) continue;
			dist[e.first] = c_dist;
			pq.push({dist[e.first], e.first});
		}
	}

	for (int i = 1; i <= n; i++)
		cout << dist[i] << " ";
	cout << "\n";
	return 0;
}