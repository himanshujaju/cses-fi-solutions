#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long ans = 0;
	while(n) {
		ans += n/5;
		n /= 5;
	}
	cout << ans << "\n";
	return 0;
}
