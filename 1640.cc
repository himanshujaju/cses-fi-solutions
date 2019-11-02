#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, reqd;
	cin >> n >> reqd;
	map<int, int> st;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x >= reqd) continue;

		int remaining = reqd - x;
		auto it = st.find(remaining);
		if (it != st.end()) {
			cout << it->second << " " << i << "\n";
			return 0;
		}

		st[x] = i;
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}
