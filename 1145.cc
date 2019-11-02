#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> st;
	while(n--) {
		int x;
		cin >> x;
		auto it = st.lower_bound(x);
		if (it != st.end())
			st.erase(it);
		st.insert(x);
	}
	cout << st.size() << "\n";
	return 0;
}