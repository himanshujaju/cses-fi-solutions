#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());

	cout << arr.size() << "\n";
	return 0;
}
