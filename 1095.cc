#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

int BigMod(int a, int b, int mod) {
	if (!b) return 1;
	int half = BigMod(a, b/2, mod);
	half = (1LL * half * half) % mod;
	if (b&1) {
		half = (1LL * half * a) % mod;
	}
	return half;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		cout << BigMod(a, b, MOD) << "\n";
	}
	return 0;
}
