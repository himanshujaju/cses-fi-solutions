#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long ans = -1000000000;
	long long curr_sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		curr_sum += x;
		ans = max(ans, curr_sum);
		curr_sum = max(curr_sum, 0LL);
	}
	cout << ans << "\n";
	return 0;
}
