#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<pair<int,int>>& arr, int idx, int rem) {
	int i = idx + 1;
	int j = (int)(arr.size()) - 1;
	while(i < j) {
		int v = arr[i].first + arr[j].first;
		if (v > rem) {
			j--;
		} else if (v < rem) {
			i++;
		} else {
			cout << arr[i].second << " " << arr[j].second << " " << arr[idx].second << "\n";
			return true;
		}
	}
	return false;
}

int main() {
	int n, reqd;
	cin >> n >> reqd;
	vector<pair<int,int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i + 1;
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		int rem = reqd - arr[i].first;
		if (possible(arr, i, rem))
			return 0;
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}