#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 1;
	string s;
	cin >> s;
	int curr = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1])
			curr += 1;
		else
			curr = 1;

		ans = max(ans, curr);
	}
	cout << ans << "\n";
	return 0;
}
