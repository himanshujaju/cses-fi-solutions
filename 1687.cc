#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200000;
constexpr int maxlog = 20;
int par[maxlog][maxn + 1];

bool IsSet(int mask, int id) {
	return ((mask >> id) & 1);
}

int main() {
	int n, q;
	cin >> n >> q;
	par[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		cin >> par[0][i];
	}

	for (int i = 1; i < maxlog; i++) {
		for (int j = 1; j <= n; j++) {
			int v = par[i - 1][j];
			par[i][j] = par[i - 1][v];
		}
	}

	while (q--) {
		int x, k;
		cin >> x >> k;
		for (int i = maxlog - 1; i >= 0; i--) {
			if (!IsSet(k, i)) continue;
			x = par[i][x];
			k -= (1 << i);
		}
		if (!x) x = -1;
		cout << x << "\n";
	}
	return 0;
}
