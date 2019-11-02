#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1000001;
bool can_win[maxn];
string s = "LW";
 
int main() {
	can_win[0] = false;
	int n, k;
	cin >> n >> k;
	vector<int> arr(k);
	for (int &x: arr)
		cin >> x;

	sort(arr.begin(), arr.end());
	for (int i = 1; i <= n; i++) {
		can_win[i] = false;
		for (int v: arr) {
			if (v > i) break;

			if (!can_win[i - v]) {
				can_win[i] = true;
				break;
			}
		}
		cout << s[can_win[i]];
	}
	return 0;
}