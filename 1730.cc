#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int v = 0;
		while(n--){
			int x;
			cin >> x;
			v ^= x;
		}

		if (v)
			cout << "first\n";
		else
			cout << "second\n";
	}
	return 0;
}