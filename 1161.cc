#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int x, n;
	cin >> x >> n;
	long long ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	for (int i = 1; i < n; i++) {
		auto item1 = pq.top();
		pq.pop();

		auto item2 = pq.top();
		pq.pop();

		int sum = item1 + item2;
		ans += sum;
		pq.push(sum);
	}
	cout << ans << "\n";
	return 0;
}
