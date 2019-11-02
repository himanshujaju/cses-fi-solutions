#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1000001;
constexpr int inf = 10000001;
int ans[maxn];
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	ans[0] = 0;
	for (int i = 1; i <= k; i++) {
		ans[i] = inf;
		for (int v: arr)
			if (i >= v)
				ans[i] = min(ans[i], 1 + ans[i - v]);
	}

	if (ans[k] == inf) ans[k] = -1;
	cout << ans[k] << "\n";
	return 0;
}