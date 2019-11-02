#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	vector<pair<pair<int, int>, int>> arr;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> v1(a, 1);
		pair<int, int> v2(b + 1, -1);
		arr.push_back({v1, i});
		arr.push_back({v2, i});
	}
	sort(arr.begin(), arr.end());
	int ans = 0, sum = 0;
	for (auto &x: arr) {
		sum += x.first.second;
		ans = max(ans, sum);
	}
	cout << ans << "\n";
	vector<int> id(n);
	set<int> st;
	for (int i = 0; i < n; i++)
		st.insert(i + 1);

	for (auto &x: arr) {
		if (x.first.second != 1) {
			st.insert(id[x.second]);
			continue;
		}
		
		auto it = st.begin();
		id[x.second] = *it;
		st.erase(it);
	}
	for (int i = 0; i < n; i++)
		cout << id[i] << " ";
	cout << "\n";
	return 0;
}