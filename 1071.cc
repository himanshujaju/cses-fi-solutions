#include <bits/stdc++.h>
using namespace std;

long long F(long long v) {
	return v * v;
}

long long GetVal(int x, int y) {
	long long ans = F(max(x, y) - 1);
	if (x > y) {
		int dist = y;
		if (x%2 == 0)
			dist = 2 * x - dist;
		ans += dist;
	} else {
		int dist = x;
		if (y%2)
			dist = 2 * y - dist;
		ans += dist;
	}
	return ans;
}
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int x, y;
		cin >> x >> y;
		cout << GetVal(x, y) << "\n";
	}
	return 0;
}