#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans = 0;
		while(n--) {
			int x;
			cin >> x;
			x %= 4;
			ans ^= x;
		}
		if (ans)
			cout << "first\n";
		else
			cout << "second\n";
	}
	return 0;
}