#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1010;
int h[maxn], s[maxn];
int dp[100001];

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		cin >> s[i];

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = x; j >= h[i]; j--) {
			dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
			ans = max(ans, dp[j]);
		}
	}
	cout << ans << "\n";
	return 0;
}