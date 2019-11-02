#include <bits/stdc++.h>
using namespace std;
 
int main() {
	multiset<int> end_time;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
		end_time.insert(0);
	vector<pair<int,int>> arr(n);
	for (auto &x: arr)
		cin >> x.first >> x.second;
	sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
		return a.second < b.second;
	});
	int ans = 0;
	for (auto x: arr) {
		auto it = end_time.upper_bound(x.first);
		if (it == end_time.begin()) continue;
		it--;
		ans += 1;
		end_time.erase(it);
		end_time.insert(x.second);
	}
	cout << ans << "\n";
	return 0;
}