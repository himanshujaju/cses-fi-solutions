#include <bits/stdc++.h>
using namespace std;

void print(const vector<int> &x) {
	cout << x.size() << "\n";
	for (int v: x)
		cout << v << " ";
	cout << "\n";
}

long long F(long long x) {
	return (x * (x + 1)) / 2;
}

int main() {
	int n;
	cin >> n;
	long long sum = F(n);
	if (sum&1) {
		cout << "NO\n";
		return 0;
	}

	sum /= 2;
	vector<int> l, r;
	for (int i = n; i >= 1; i--) {
		if (i <= sum) {
			sum -= i;
			l.push_back(i);
		} else {
			r.push_back(i);
		}
	}

	cout << "YES\n";
	print(l);
	print(r);
	return 0;
}
