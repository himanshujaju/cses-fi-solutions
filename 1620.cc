#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int>& arr, long long t, int reqd) {
	for (int x: arr) {
		long long v = t / x;
		if (v >= reqd)
			return true;
		reqd -= v;
	}
	return false;
}
 
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;
	sort(arr.begin(), arr.end());

	long long lo = 0, hi = (1LL << 60);
	while(lo < hi) {
		long long mid = (lo + hi) >> 1;
		if (possible(arr, mid, x))
			hi = mid;
		else
			lo = mid + 1;
	}
	cout << lo << "\n";
	return 0;
}