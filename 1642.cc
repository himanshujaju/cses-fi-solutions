#include <bits/stdc++.h>
using namespace std;

void print(const vector<int>& pos) {
	for (int x: pos)
		cout << (x + 1) << " ";
	cout << "\n";
}

int main() {
	map<int, pair<int, int>> lhs;
	int n, reqd;
	cin >> n >> reqd;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			lhs[arr[i] + arr[j]] = {i, j};
		for (int j = i + 2; j < n; j++) {
			int v = arr[j] + arr[i + 1];
			auto it = lhs.find(reqd - v);
			if (it == lhs.end()) continue;

			print({it->second.first, it->second.second, i + 1, j});
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}