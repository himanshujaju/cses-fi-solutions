#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1000010;
constexpr int alphabets = 4;
int pos[maxn][alphabets];
string s = "ACTG";

int GetID(char ch) {
	for (int i = 0; i < s.size(); i++)
		if (s[i] == ch)
			return i;
	return -1;
}

int main() {
	string str;
	cin >> str;
	int N = str.size();
	pos[N][0] = pos[N][1] = pos[N][2] = pos[N][3] = maxn;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < alphabets; j++)
			pos[i][j] = pos[i + 1][j];
		int id = GetID(str[i]);
		pos[i][id] = i;
	}

	string ans = "";
	int p = -1;
	while (p < N) {
		int mx = 0;
		for (int i = 0; i < alphabets; i++)
			mx = max(mx, pos[p + 1][i]);

		for (int i = 0; i < alphabets; i++) {
			if (pos[p + 1][i] == mx) {
				ans += s[i];
				p = pos[p + 1][i];
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}