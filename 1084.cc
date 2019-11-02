#include <bits/stdc++.h>
using namespace std;

bool InRange(int x, int l, int r) {
	return (x >= l && x <= r);
}
 
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> desired(n);
	for (int &x: desired)
		cin >> x;
	sort(desired.begin(), desired.end());
	vector<int> sz(m);
	for (int &x: sz)
		cin >> x;
	sort(sz.begin(), sz.end());
	int ans = 0;
	int i = 0, j = 0;

	while(i < n && j < m) {
		if (InRange(sz[j], desired[i] - k, desired[i] + k)) {
			ans += 1;
			i += 1;
			j += 1;
			continue;
		}
		if (sz[j] < desired[i] - k) {
			j += 1;
			continue;
		}
		i += 1;
	}

	cout << ans << "\n";
	return 0;
}