#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100001;
int degree[maxn];
vector<int> G[maxn];

int main() {
	int n, m;
	cin >> n >> m;
	while(m--) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		degree[b] += 1;
	}
	queue<int> Q;
	for (int i = 1; i <= n; i++) {
		if (!degree[i])
			Q.push(i);
	}

	vector<int> ans;
	while(!Q.empty()) {
		auto ele = Q.front();
		Q.pop();
		ans.push_back(ele);

		for (int v: G[ele]) {
			degree[v] -= 1;
			if (!degree[v])
				Q.push(v);
		}
	}

	if (ans.size() != n)
		cout << "IMPOSSIBLE\n";
	else {
		for (int v: ans)
			cout << v << " ";
		cout << "\n";
	}
	return 0;
}