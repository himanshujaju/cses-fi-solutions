#include <bits/stdc++.h>
using namespace std;

void insert(vector<pair<int,int>>& arr, pair<int, int> v) {
	while(!arr.empty()) {
		pair<int, int> ele = arr.back();
		if (ele.second >= v.second)
			arr.pop_back();
		else
			break;
	}
	arr.push_back(v);
}

int GetPosition(const vector<pair<int,int>>& arr, int v) {
	int n = arr.size();
	if (!n) return 0;
	if (arr[0].second >= v) return 0;
	int lo = 0, hi = n - 1;
	while(lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (arr[mid].second < v)
			lo = mid;
		else
			hi = mid - 1;
	}
	return arr[lo].first;
}
 
int main() {
	vector<pair<int, int>> dq;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cout << GetPosition(dq, x) << " ";
		insert(dq, {i, x});
	}
	return 0;
}