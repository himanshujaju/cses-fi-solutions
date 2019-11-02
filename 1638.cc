#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1000000007;
constexpr int maxn = 1010;

int trap[maxn][maxn];
int dp[maxn][maxn];

int _add(int a, int b){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
			trap[i][j] = (s[j - 1] == '*');
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == 1 && j == 1) {
				dp[i][j] = !trap[i][j];
				continue;
			}

			if (trap[i][j])
				dp[i][j] = 0;
			else
				dp[i][j] = _add(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[n][n] << "\n";
	return 0;
}
