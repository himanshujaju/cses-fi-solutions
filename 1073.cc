#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	multiset<int> tower_heads;
	while(n--) {
		int x;
		cin >> x;
		auto it = tower_heads.upper_bound(x);
		if (it != tower_heads.end())
			tower_heads.erase(it);
		tower_heads.insert(x);
	}
	cout << tower_heads.size() << "\n";
	return 0;
}