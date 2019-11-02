#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1010;
int n, m;
string arr[maxn];
bool vis[maxn][maxn];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool ok(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void explore(int x, int y) {
	if (vis[x][y]) return;
	vis[x][y] = 1;
	if (arr[x][y] == '#') return;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (ok(nx, ny))
			explore(nx, ny);
	}
}

int main() {
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			if (arr[i][j] == '#') continue;
			explore(i, j);
			ans += 1;
		}
	}
	cout << ans << "\n";
	return 0;
}