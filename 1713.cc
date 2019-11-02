#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000010;
int ans[MAXN];

int main() {
	for (int i = 1; i < MAXN; i++)
		for (int j = i; j < MAXN; j += i)
			ans[j] += 1;

	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		cout << ans[x] << "\n";
	}
	return 0;
}
