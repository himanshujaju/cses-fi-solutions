#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, pair<int,int>> DijkstraNode;
typedef priority_queue<DijkstraNode, vector<DijkstraNode>, greater<DijkstraNode>> DijkstraPQ;

constexpr int maxn = 100010;
constexpr long long inf = (1LL << 62);
long long dist[maxn][2];
vector<pair<int,int>> G[maxn];

void add(DijkstraPQ& pq, int node, int layer, long long curr_dist) {
	if (dist[node][layer] <= curr_dist) return;
	dist[node][layer] = curr_dist;

	pq.push({curr_dist, {node, layer}});
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		dist[i][0] = dist[i][1] = inf;

	while(m--) {
		int u, v, c;
		cin >> u >> v >> c;
		G[u].push_back({v, c});
	}

	DijkstraPQ pq;
	add(pq, 1, 0, 0);
	add(pq, 1, 1, 0);

	while(!pq.empty()) {
		auto ele = pq.top();
		pq.pop();

		pair<int, int> node = ele.second;
		int vertex = node.first;
		int layer = node.second;

		if (dist[vertex][layer] != ele.first) continue;

		for (auto &v: G[vertex]) {
			long long total_dist = v.second + ele.first;
			add(pq, v.first, layer, total_dist);

			if (!layer) {
				total_dist = ele.first + (v.second / 2);
				add(pq, v.first, layer + 1, total_dist);
			}
		}
	}

	cout << dist[n][1] << "\n";
	return 0;
}