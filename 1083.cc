#include <bits/stdc++.h>
using namespace std;

long long S(long long x) {
	return (x * (x + 1)) / 2;
}

int main() {
	int n;
	cin >> n;
	long long ans = S(n);
	for (int i = 1; i < n; i++) {
		int x;
		cin >> x;
		ans -= x;
	}
	cout << ans << "\n";
	return 0;
}
