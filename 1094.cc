#include <bits/stdc++.h>
using namespace std;

int main() {
	long long ans = 0;
	int n;
	cin >> n;
	int last_num = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x < last_num)
			ans += (last_num - x);
		else
			last_num = x;
	}
	cout << ans << "\n";
	return 0;
}
