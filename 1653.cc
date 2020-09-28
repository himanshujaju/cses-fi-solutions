#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 20;
int arr[maxn];
int dp[1 << maxn];

inline bool IsSet(int mask, int id) {
	return ((mask >> id) & 1);
}

int solve(int mask, int n, int reqd);

void go(int curr_mask, long long curr_sum, int id, const vector<int>& pos, int orig_mask, int reqd, int min_skipped, int n, int& out) {
	if (id == pos.size()) {
		if (curr_sum + min_skipped <= reqd) return;
		out = min(out, 1 + solve(orig_mask ^ curr_mask, n, reqd));
		return;
	}

	int orig_id = pos[id];
	int val = arr[orig_id];

	if ((curr_sum + val) > reqd) {
		if (min_skipped && (curr_sum + min_skipped) <= reqd) return;
		out = min(out, 1 + solve(orig_mask ^ curr_mask, n, reqd));
		return;
	}

	go(curr_mask | (1 << orig_id), curr_sum + val, id + 1, pos, orig_mask, reqd, min_skipped, n, out);

	if (!min_skipped) min_skipped = val;

	while (id < pos.size() && arr[pos[id]] == val) id++;
	go(curr_mask, curr_sum, id, pos, orig_mask, reqd, min_skipped, n, out);
}

int solve(int mask, int n, int reqd) {
	if (!mask) return 0;
	if (dp[mask] != -1) return dp[mask];

	vector<int> pos;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (!IsSet(mask, i)) continue;
		pos.push_back(i);
		sum += arr[i];
	}

	if (sum <= reqd) {
		dp[mask] = 1;
		return dp[mask];
	}

	dp[mask] = maxn;
	go((1 << pos[0]), arr[pos[0]], 1, pos, mask, reqd, 0, n, dp[mask]);
	return dp[mask];
}

int main() {
	memset(dp, -1, sizeof(dp));

	int n, reqd;
	cin >> n >> reqd;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cout << solve((1 << n) - 1, n, reqd) << "\n";
	return 0;
}
