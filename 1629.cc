#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr.push_back({a, b});
	}
	sort(arr.begin(), arr.end(),
		[](const pair<int,int> &a, const pair<int,int> &b){
			return a.second < b.second;
		});
	int last_taken = 0, ans = 0;
	for (auto &x: arr) {
		if (x.first >= last_taken) {
			ans += 1;
			last_taken = x.second;
		}
	}
	cout << ans << "\n";
	return 0;
}