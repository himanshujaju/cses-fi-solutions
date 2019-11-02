#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a = 0;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (i&1)
				a ^= x;
		}
		if (a)
			cout << "first\n";
		else
			cout << "second\n";
	}
	return 0;
}