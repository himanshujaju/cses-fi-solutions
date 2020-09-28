#include <bits/stdc++.h>
using namespace std;

int IsSet(int mask, int pos) {
	return ((mask >> pos) & 1);
}

void go(int offset, int n, const vector<int>& arr, int reqd, map<int, int>& ret, int idx, int sum) {
	if (sum > reqd)
		return;

	if (idx == n) {
		ret[sum] += 1;
		return;
	}

	go(offset, n, arr, reqd, ret, idx + 1, sum);
	go(offset, n, arr, reqd, ret, idx + 1, sum + arr[offset + idx]);
}

map<int, int> solve(int l, int r, const vector<int>& arr, int reqd) {
	map<int, int> ret;
	int offset = l;
	int items = (r - l + 1);

	go(offset, items, arr, reqd, ret, 0, 0);
	return ret;
}
 
int main() {
	int n, reqd;
	cin >> n >> reqd;
	vector<int> arr(n);
	for (auto& x: arr)
		cin >> x;

	if (n == 1) {
		int ans = (arr[0] == reqd);
		cout << ans << "\n";
		return 0;
	}

	int mid = n >> 1;
	map<int, int> lhs = solve(0, mid, arr, reqd);
	map<int, int> rhs = solve(mid + 1, n - 1, arr, reqd);

	long long ans = 0;
	for (const auto& x: rhs) {
		int rem = reqd - x.first;
		auto iter = lhs.end();
		if (iter == lhs.begin()) break;
		iter--;

		while(iter != lhs.begin()) {
			if (iter->first <= rem)
				break;
			auto temp = iter;
			iter--;
			lhs.erase(temp);
		}

		if (iter->first != rem)
			continue;

		ans += (1LL * x.second * iter->second);
		lhs.erase(iter);
	}
	cout << ans << "\n";
	return 0;
}
