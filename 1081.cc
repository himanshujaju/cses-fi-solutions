#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1000010;
int mark[MAXN];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int x;
		cin >> x;
		mark[x] += 1;
	}

	for (int i = MAXN - 1; i > 0; i--) {
		int ctr = 0;
		for (int j = i; j < MAXN && ctr <= 1; j += i)
			ctr += mark[j];

		if (ctr > 1) {
			cout << i << "\n";
			break;
		}
	}
	return 0;
}
