#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1010;

bool vis[maxn][maxn];
pair<int,int> from[maxn][maxn];
char ch[maxn][maxn];
string arr[maxn];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string s = "RDLU";
 
int main() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> arr[i];

	int x = -1, y = -1;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'A') {
				x = i;
				y = j;
			}
			vis[i][j] = 0;
		}

	queue<pair<int, int>> bfs;
	bfs.push({x, y});
	vis[x][y] = 1;
	int final_x = -1, final_y = -1;
	while(!bfs.empty()) {
		auto ele = bfs.front();
		bfs.pop();

		if (arr[ele.first][ele.second] == 'B') {
			final_x = ele.first;
			final_y = ele.second;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = ele.first + dx[i];
			int ny = ele.second + dy[i];
			
			if (!(nx >= 0 && ny >= 0 && nx < r && ny < c)) continue;
			if (vis[nx][ny] || arr[nx][ny] == '#') continue;

			vis[nx][ny] = 1;
			from[nx][ny] = {ele.first, ele.second};
			ch[nx][ny] = s[i];
			bfs.push({nx, ny});
		}
	}

	if (final_x < 0) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	string ans = "";
	while(arr[final_x][final_y] != 'A') {
		ans += ch[final_x][final_y];
		auto it = from[final_x][final_y];
		final_x = it.first;
		final_y = it.second;
	}
	reverse(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	cout << ans << "\n";

	return 0;
}