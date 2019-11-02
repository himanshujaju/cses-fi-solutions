#include <bits/stdc++.h>
using namespace std;
 
int main() {
	long long mx = 0, sum = 0;
	int n;
	cin >> n;
	while(n--){
		long long x;
		cin >> x;
		sum += x;
		mx = max(mx, x);
	}
	long long ans = 2 * mx;
	if ((sum - mx) > mx)
		ans = sum;
	cout << ans << "\n";
	return 0;
}