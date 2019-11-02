#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200010;
long long arr[maxn];
 
int main() {
	multiset<long long> st;
	int n, a, b;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	long long ans = LONG_LONG_MIN;

	for (int i = a; i <= n; i++) {
		st.insert(arr[i - a]);
		if (i > b + 1)
			st.erase(st.find(arr[i - b - 1]));
		ans = max(ans, arr[i] - *st.begin());
	}

	cout << ans << "\n";
	return 0;
}