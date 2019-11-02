#include <bits/stdc++.h>
using namespace std;

constexpr long long inf = (1LL << 60);
constexpr int maxn = 510;
long long dist[maxn][maxn];

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = (i == j) ? 0 : inf;
		}
	}

	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], 1LL*c);
		dist[b][a] = min(dist[b][a], 1LL*c);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
			}
		}
	}

	while (q--) {
		int u, v;
		cin >> u >> v;
		long long ans = (dist[u][v] == inf) ? -1 : dist[u][v];
		cout << ans << "\n";
	}

	return 0;
}