#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, n;
	cin >> x >> n;
	set<int> lights;
	multiset<int> distances;
	lights.insert({0, x});
	distances.insert(x);

	while(n--) {
		int pos;
		cin >> pos;
		auto i = lights.upper_bound(pos);
		auto j = i;
		j--;

		int v1 = *i;
		int v2 = *j;

		distances.erase(distances.find(v1 - v2));
		lights.insert(pos);
		distances.insert(v1 - pos);
		distances.insert(pos - v2);

		auto it = distances.end();
		it--;
		cout << *it << "\n";
	}
	return 0;
}