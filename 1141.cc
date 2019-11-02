#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> st;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	int ans = 0;
	int l = 0;
	for (int r = 0; r < n; r++) {
		while(st.count(arr[r])) {
			st.erase(arr[l]);
			l++;
		}

		st.insert(arr[r]);
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return 0;
}