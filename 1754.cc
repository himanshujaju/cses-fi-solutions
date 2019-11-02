#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a, b;
		cin >> a >> b;
		int s = a + b;
		if (s%3) {
			cout << "NO\n";
			continue;
		}

		s /= 3;
		if (s <= min(a, b))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
