#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 100010;
bitset<maxn> res;

int main() {
	res.set(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	for (int x: arr)
		res = res | (res << x);

	string s = res.to_string();
	int ans = res.count();
	cout << ans - 1 << "\n";
	for (int i = 1; i < s.size(); i++) {
		if (res[i])
			cout << i << " ";
	}
	return 0;
}
