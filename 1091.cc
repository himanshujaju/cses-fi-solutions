#include <bits/stdc++.h>
using namespace std;

int getAnswer(multiset<int>& st, int x) {
	auto it = st.upper_bound(x);
	if (it == st.begin()) return -1;
	it--;
	int v = *it;
	st.erase(it);
	return v;
}

int main() {
	int n, m;
	cin >> n >> m;
	multiset<int> st;
	while(n--) {
		int x;
		cin >> x;
		st.insert(x);
	}
	while(m--){
		int x;
		cin >> x;
		cout << getAnswer(st, x) << "\n";
	}
	return 0;
}
