#include <bits/stdc++.h>
using namespace std;

int subarrays(const vector<int>& arr, long long v) {
	int ret = 0;
	int i = 0;
	int n = arr.size();
	while(i < n) {
		int j = i;
		long long s = 0;
		while(j < n) {
			s += arr[j];
			if (s > v)
				break;
			j += 1;
		}

		ret += 1;
		i = j;
	}
	return ret;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	long long hi = 0, lo = 0;
	for (int x: arr) {
		lo = max(lo, 1LL * x);
		hi += x;
	}

	while (lo < hi) {
		long long mid = (lo + hi) >> 1;
		if (subarrays(arr, mid) > k)
			lo = mid + 1;
		else
			hi = mid;
	}

	cout << lo << "\n";
	return 0;
}