#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int arr[26] = {0};
	for (char ch: s)
		arr[(int)(ch - 'A')] += 1;

	int odd = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i]&1)
			odd++;
	}

	if (odd > 1) {
		cout << "NO SOLUTION\n";
		return 0;
	}

	string pal = "";
	string odds = "";
	for (int i = 0; i < 26; i++) {
		pal += string(arr[i]/2, 'A' + i);
		if (arr[i]&1)
			odds += (char)('A' + i);
	}
	cout << pal + odds;
	reverse(pal.begin(), pal.end());
	cout << pal << "\n";
	return 0;
}
