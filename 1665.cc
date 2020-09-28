#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int dp[2][51][10001];
int arr[101];

int _mult(int a, int b) {
	return (1LL * a * b) % mod;
}

int _add(int a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	return a;
}

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	sort(arr + 1, arr + n + 1);

	int max_open = n/2;
	dp[0][0][5000] = 1;

	for (int i = 1; i <= n; i++) {
		int curr = i & 1;
		int prev = curr ^ 1;

		for (int open = 0; open <= max_open; open++) {
			for (int sum = 0; sum <= 10000; sum++) {
				dp[curr][open][sum] = 0;


				int v = dp[prev][open][sum];
				if ((sum - arr[i]) >= 0 && (open != max_open)) {
					v = _add(v, dp[prev][open + 1][sum - arr[i]]);
				}
				v = _mult(v, open + 1);

				if ((sum + arr[i]) <= 10000 && open > 0) {
					v = _add(v, dp[prev][open - 1][sum + arr[i]]);
				}

				dp[curr][open][sum] = v;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= x; i++) {
		ans = _add(ans, dp[n&1][0][5000 + i]);
	}
	cout << ans << "\n";
	return 0;
}
