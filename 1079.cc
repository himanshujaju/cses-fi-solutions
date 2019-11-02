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
constexpr int maxn = 1000001;
int fact[maxn], inverse_fact[maxn];

int choose(int n, int r) {
	int ret = _mult(inverse_fact[n - r], inverse_fact[r], mod);
	ret = _mult(ret, fact[n], mod);
	return ret;
}
 
int main() {
	fact[0] = inverse_fact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = _mult(fact[i - 1], i, mod);
	inverse_fact[maxn - 1] = _inverse(fact[maxn - 1], mod);
	for (int i = maxn - 2; i > 0; i--)
		inverse_fact[i] = _mult(inverse_fact[i + 1], i + 1, mod);

	int n;
	cin >> n;
	while(n--) {
		int a, b;
		cin >> a >> b;
		cout << choose(a, b) << "\n";
	}
	return 0;
}