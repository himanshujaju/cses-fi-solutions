#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (auto &x: arr)
		cin >> x.first >> x.second;
	sort(arr.begin(), arr.end());
	long long ans = 0, curr_time = 0;
	for (auto x: arr) {
		curr_time += x.first;
		ans += x.second - curr_time;
	}
	cout << ans << "\n";
	return 0;
}