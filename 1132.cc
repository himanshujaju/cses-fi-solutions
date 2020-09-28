#include <bits/stdc++.h>
using namespace std;

constexpr int UNVISITED = -1;

vector<int> BFS(int source, int nodes, const vector<vector<int>>& edges) {
	queue<int> Q;
	vector<int> distances(nodes, UNVISITED);

	distances[source] = 0;
	Q.push(source);
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (int v: edges[u]) {
			if (distances[v] != UNVISITED)
				continue;

			distances[v] = distances[u] + 1;
			Q.push(v);
		}
	}
	return distances;
}

int GetFarthestNode(const vector<int>& distances) {
	auto iter = std::max_element(distances.begin(), distances.end());
	return std::distance(distances.begin(), iter);
}
 
int main() {
	int nodes;
	cin >> nodes;
	vector<vector<int>> edges(nodes);
	for (int i = 1; i < nodes; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[v].push_back(u);
		edges[u].push_back(v);
	}

	int diameter_node1 = GetFarthestNode(BFS(0, nodes, edges));
	vector<int> distances_node1 = BFS(diameter_node1, nodes, edges);

	int diameter_node2 = GetFarthestNode(distances_node1);
	vector<int> distances_node2 = BFS(diameter_node2, nodes, edges);

	for (int i = 0; i < nodes; i++) {
		cout << max(distances_node1[i], distances_node2[i]) << " ";
	}
	cout << "\n";
	return 0;
}
