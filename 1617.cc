#include <bits/stdc++.h>
using namespace std;

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
	const int mod = 1000000007;
	int n;
	cin >> n;
	cout << BigMod(2, n, mod) << "\n";
	return 0;
}
