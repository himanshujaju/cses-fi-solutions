#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1000000007;
int arr[1000001];

int _add(int a, int b){
	a += b;
	if(a >= mod) a -= mod;
	return a;
}

int _mult(int a, int b){
	return (1LL * a * b) % mod;
}

int main() {
	int n;
	cin >> n;
	arr[0] = arr[2] = 1;
	arr[1] = 0;

	for (int i = 3; i <= n; i++) {
		arr[i] = _mult(_add(arr[i - 1], arr[i - 2]), i - 1);
	}

	cout << arr[n] << "\n";
	return 0;
}
