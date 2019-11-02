#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;
	sort(arr.begin(), arr.end());
	int v = arr[n / 2];
	long long ans = 0;
	for (int x: arr)
		ans += abs(v - x);
	cout << ans << "\n";
	return 0;
}
