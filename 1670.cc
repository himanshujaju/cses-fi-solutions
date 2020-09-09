#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> dist;

int dx[2] = {0, 1};
int dy[2] = {1, 0};

vector<pair<int, int>> edges;

bool IsTerminal(const string& s) {
	for (int i = 0; i < 9; i++) {
		if ((s[i] - '0') != i) return false;
	}
	return true;
}

int F(int x, int y) {
	return 3 * x + y;
}
 
int main() {
	string s = "";
	for (int i = 0; i < 9; i++) {
		int x;
		cin >> x;
		s += (char)('0' + x - 1);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int dir = 0; dir < 2; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];

				if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
					edges.push_back({F(i, j), F(nx, ny)});
				}
			}
		}
	}
	
	queue<string> bfs;
	bfs.push(s);
	dist[s] = 0;

	while(!bfs.empty()) {
		auto item = bfs.front();
		bfs.pop();

		if (IsTerminal(item)) {
			cout << dist[item] << "\n";
			return 0;
		}

		int new_dist = dist[item] + 1;
		for (auto& x: edges) {
			swap(item[x.first], item[x.second]);
			auto iter = dist.insert({item, new_dist});
			if (iter.second)
					bfs.push(item);
			swap(item[x.first], item[x.second]);
		}
	}
	return 0;
}
