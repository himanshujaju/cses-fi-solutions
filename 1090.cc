#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	sort(arr.begin(), arr.end());
	int ans = n;
	int i = 0, j = n - 1;
	while(i < j) {
		if (arr[i] + arr[j] <= x) {
			i += 1;
			j -= 1;
			ans -= 1;
		} else {
			j -= 1;
		}
	}
	cout << ans << "\n";
	return 0;
}