#include <bits/stdc++.h>
using namespace std;

#define sz(s) (int)(s.size())

vector<int> z_function(const string& s) {
	vector<int> z(sz(s));
	int L = 0, R = 0;
	for(int i = 1; i < sz(s); i++) {
		if(i <= R)
			z[i] = min(z[i - L],R - i + 1);
		while((i + z[i] < sz(s)) && s[z[i]] == s[i + z[i]])
			z[i]++;
		if(i + z[i] - 1 > R) {
			L = i;
			R = i + z[i] - 1;
		}
	}
	return z;
}
 
int main() {
	string a, b;
	cin >> b >> a;
	string temp = a + "$" + b;
	vector<int> z = z_function(temp);
	int reqd = sz(a);
	int ans = 0;
	for (int i = sz(a) + 1; i < sz(temp); i++) {
		if (z[i] == reqd)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}