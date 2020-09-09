#include <bits/stdc++.h>
using namespace std;
 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
 
int reqd_x = 6;
int reqd_y = 0;
string s;
map<char, int> mp;
bool vis[8][8];
 
bool ok(int x, int y) {
	int horizontal_left = 0;
	if (x == 0 || vis[x - 1][y])
		horizontal_left += 1;
	if (x == 6 || vis[x + 1][y])
		horizontal_left += 1;
 
	int vertical_left = 0;
	if (y == 0 || vis[x][y - 1])
		vertical_left += 1;
	if (y == 6 || vis[x][y + 1])
		vertical_left += 1;
 
	int v1 = min(horizontal_left, vertical_left);
	int v2 = max(horizontal_left, vertical_left);
 
	return (v1 != 0 || v2 == 1);
}
 
int solve(int x, int y, int id) {
	if (id == s.size()) return (x == reqd_x && y == reqd_y);
	if (vis[reqd_x][reqd_y] || !ok(x, y)) return 0;
 
	int ret = 0;
	if (s[id] == '?') {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx > 6 || ny > 6 || vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			ret += solve(nx, ny, id + 1);
			vis[nx][ny] = 0;
		}
	} else {
			int i = mp[s[id]];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx < 0 || ny < 0 || nx > 6 || ny > 6 || vis[nx][ny])) {
			vis[nx][ny] = 1;
			ret += solve(nx, ny, id + 1);
			vis[nx][ny] = 0; }
	}
 
	return ret;
}
 
int main() {
	mp['D'] = 0;
	mp['R'] = 3;
	mp['L'] = 1;
	mp['U'] = 2;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			vis[i][j] = 0;
	cin >> s;
	vis[0][0] = 1;
	cout << solve(0, 0, 0) << "\n";
	return 0;
}