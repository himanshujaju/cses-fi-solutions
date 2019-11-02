#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200010;
int height[maxn];
stack<int> st; // increasing order.

int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> height[i];
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		while(!st.empty())
		{
			int u = height[st.top()];
			int v = height[i];
			if (u <= v) break;

			st.pop();
			if (st.empty())
				ans = max(ans,1LL * u * (i - 1));
			else
				ans = max(ans, 1LL * u * (i - st.top() - 1));
		}
		st.push(i);
	}
	while(!st.empty())
	{
		int u = height[st.top()];
		st.pop();
		if(st.empty())
			ans = max(ans, 1LL * u * n);
		else
			ans = max(ans, 1LL * u * (n - st.top()));
	}
	cout << ans << "\n";
	return 0;
}