#include <bits/stdc++.h>
using namespace std;

int maxDig(int n) {
	int ret = 0;
	while(n) {
		ret = max(ret, n%10);
		n /= 10;
	}
	return ret;
}

int ans(int n) {
	if (!n) return 0;
	int b = maxDig(n);
	return 1 + ans(n - b);
}

int main() {
	int n;
	cin >> n;
	cout << ans(n) << "\n";
	return 0;
}
