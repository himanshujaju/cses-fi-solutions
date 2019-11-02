#include <bits/stdc++.h>
using namespace std;

struct pt {
	int x, y;
	pt(int _x, int _y) : x(_x), y(_y) {}
};

int reserved[8][8];

bool attack(pt a, pt b) {
	int dx = abs(a.x - b.x);
	int dy = abs(a.y - b.y);

	return (dx == 0 || dy == 0 || dx == dy);
}

bool ok(const vector<pt>& placed, pt p) {
	for (pt q: placed) {
		if (attack(p, q))
			return false;
	}
	return true;
}

int ways(vector<pt> placed) {
	if (placed.size() == 8) return 1;
	int ret = 0;

	int used_rows[8] = {0};
	int used_cols[8] = {0};
	for (pt p: placed) {
		used_cols[p.y] = 1;
		used_rows[p.x] = 1;
	}

	int sx = (placed.size() == 0) ? 0 : placed.back().x;

	for (int i = sx; i < 8; i++) {
		if (used_rows[i]) continue;
		for (int j = 0; j < 8; j++) {
			if (used_cols[j] || reserved[i][j]) continue;

			if (!ok(placed, {i, j})) continue;
			placed.emplace_back(i, j);
			ret += ways(placed);
			placed.pop_back();
		}
	}
	
	return ret;
}

int main() {
	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '*')
				reserved[i][j] = 1;
			else
				reserved[i][j] = 0;
		}
	}

	int ans = ways({});
	cout << ans << "\n";
	return 0;
}
