#include <bits/stdc++.h>
using namespace std;

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

constexpr int mod = 1000000007;
constexpr int limit = 1000000;

int F(long long x, int mod) {
	long long v1 = x;
	long long v2 = x + 1;
	if (v1%2 == 0)
		v1 /= 2;
	else
		v2 /= 2;
	v1 %= mod;
	v2 %= mod;
	return _mult(v1, v2, mod);
}

int sum(long long l, long long r, int mod) {
	return _sub(F(r, mod), F(l - 1, mod), mod);
}

int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	long long last_num = n;
	for (int c = 1; last_num >= limit; c++) {
		long long v1 = n / c;
		long long v2 = n / (c + 1) + 1;
		ans = _add(ans, _mult(c, sum(v2, v1, mod), mod), mod);
		last_num = v2 - 1;
	}
	for (int i = 1; i <= (int)(last_num); i++) {
		ans = _add(ans, _mult(i, ((n/i) % mod), mod), mod);
	}
	cout << ans << "\n";
	return 0;
}