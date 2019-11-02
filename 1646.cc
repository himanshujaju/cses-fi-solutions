#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 300000;
long long sum[maxn];

int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	while(q--){
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
	return 0;
}
