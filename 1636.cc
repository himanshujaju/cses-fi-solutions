#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1000001;
constexpr int mod = 1000000007;
int ans[maxn];

int _add(int a, int b){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}
 
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	ans[0] = 1;

	for (int v: arr) {
		for (int i = v; i <= k; i++)
			ans[i] = _add(ans[i], ans[i - v]);
	}

	cout << ans[k] << "\n";
	return 0;
}