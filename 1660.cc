#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long ans = 0;
	map<long long, int> prefix_sum_ctr;
	long long prefix_sum = 0;

	prefix_sum_ctr[prefix_sum] += 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		prefix_sum += x;

		auto it = prefix_sum_ctr.find(prefix_sum - k);
		if (it != prefix_sum_ctr.end())
			ans += it->second;

		prefix_sum_ctr[prefix_sum] += 1;
	}

	cout << ans << "\n";
	return 0;
}
