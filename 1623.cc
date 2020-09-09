#include <bits/stdc++.h>
using namespace std;

long long solve(const vector<int> &arr, int id, long long diff) {
	if (id == arr.size()) return abs(diff);
	return min(solve(arr, id + 1, diff + arr[id]), solve(arr, id + 1, diff - arr[id]));
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	long long min_diff = solve(arr, 0, 0);
	cout << min_diff << "\n";
	return 0;
}
