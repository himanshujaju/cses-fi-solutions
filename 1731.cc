#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5001;
constexpr int mod = 1000000007;
constexpr int base = 37;

int dp[maxn];
set<int> hashed_words[maxn];

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

int GetHash(const std::string& word) {
	int hash = 0;

	for (char ch: word) {
		int val = (int)(ch);
		hash = _add(_mult(hash, base, mod), val, mod);
	}
	return hash;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();

	int k;
	cin >> k;
	set<int> possible_lengths;

	for (int i = 0; i < k; i++) {
		string x;
		cin >> x;
		int l = x.size();
		if (l > n) continue;
		possible_lengths.insert(l);
		hashed_words[l].insert(GetHash(x));
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int hash = 0;
		for (int j = i; j <= n; j++) {
			int val = (int)(s[j - 1]);
			hash = _add(_mult(hash, base, mod), val, mod);

			int len = j - i + 1;
			if (!hashed_words[len].count(hash)) continue;
			dp[j] = _add(dp[j], dp[i - 1], mod);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}