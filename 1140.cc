#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200010;
long long dp[maxn];
vector<pair<pair<int,int>,int>> arr;

int GetNextPos(int v) {
	pair<pair<int,int>, int> val = make_pair(make_pair(v, -1), -1);
	int pos = (int)(upper_bound(arr.begin(), arr.end(), val) - arr.begin());
	return pos;
}

long long solve(int id) {
	if (id == arr.size()) return 0;
	else if (dp[id] != -1) return dp[id];
	long long ret = solve(id + 1);
	int pos = GetNextPos(arr[id].first.second + 1);
	ret = max(ret, 1LL * arr[id].second + solve(pos));
	return (dp[id] = ret);
}

int main() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	arr.resize(n);
	for (auto &x: arr)
		cin >> x.first.first >> x.first.second >> x.second;
	sort(arr.begin(), arr.end());
	cout << solve(0) << "\n";
	return 0;
}