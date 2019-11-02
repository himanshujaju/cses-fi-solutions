#include <bits/stdc++.h>
using namespace std;

long long GetVal(const vector<int>& arr, int start, int end) {
	long long ret = 0;
	for (int i = start; i <= end; i++) {
		ret *= 2;
		ret += arr[i];
	}
	return ret;
}

long long POWER(int a, int b) {
	long long ret = 1;
	for (int i = 1; i <= b; i++)
		ret *= a;
	return ret;
}

long long F(const vector<int>& arr) {
	long long ret = 0;
	int N = arr.size();
	for (int i = 0; i < N; i++) {
		ret += GetVal(arr, 0, i - 1) * POWER(2, N - i - 1);
		if (arr[i])
			ret += GetVal(arr, i + 1, N - 1) + 1;
	}
	return ret;
}

int main() {
	long long n;
	cin >> n;
	vector<int> bits;
	while(n) {
		bits.push_back(n&1);
		n /= 2;
	}
	reverse(bits.begin(), bits.end());
	cout << F(bits) << "\n";
	return 0;
}