#include <bits/stdc++.h>
using namespace std;

constexpr int maxsum = 62750;
constexpr int maxn = 501;
constexpr int mod = 1000000007;

int _add(int a, int b, int mod){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int _sub(int a, int b, int mod){
	a -= b;
	if(a < 0) a += mod;
	return a;
}

int _mult(int a, int b, int mod){
	return (1LL * a * b) % mod;
}

int _power(int a, int b, int mod){
	if(!b) return 1;
	int x = _power(a, b >> 1, mod);
	x = _mult(x, x, mod);
	if(b&1) x = _mult(x, a, mod);
	return x;
}

int _inverse(int x, int mod){
	return _power(x, mod - 2, mod);
}

int _div(int a, int b, int mod){
	return _mult(a, _inverse(b, mod), mod);
}

int ways[maxn][maxsum];

int main() {
	ways[0][0] = 1;
	int n;
	cin >> n;
	int tot = n * (n + 1);
	if (tot%4) {
		cout << "0\n";
		return 0;
	}
	tot /= 4;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
		for (int j = 0; j <= min(sum, tot); j++) {
			ways[i][j] = ways[i - 1][j];
			if (i <= j)
				ways[i][j] = _add(ways[i][j], ways[i - 1][j - i], mod);
		}
	}
	int ans = _div(ways[n][tot], 2, mod);
	cout << ans << "\n";
	return 0;
}