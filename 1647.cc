#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1000000000;

struct node {
	int range_min;
	
	node() {
		range_min = inf;
	}
};

class SegmentTree {
public:
	SegmentTree(int n) : n_(n) {
		tree_.resize(4 * n_);
	}
	~SegmentTree() = default;

	node range_query(int lQ, int rQ, int l, int r, int pos = 1) {
		if (l > rQ || r < lQ || lQ > rQ) return node();
		else if (l >= lQ && r <= rQ) return tree_[pos];
		
		int mid = (l + r) / 2;
		node L = range_query(lQ, rQ, l, mid, 2 * pos);
		node R = range_query(lQ, rQ, mid + 1, r, 2 * pos + 1);
		return merge(L, R);
	}

	void point_update(int idx, int val, int l, int r, int pos = 1) {
		if (l == r) {
			tree_[pos].range_min = val;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= idx)
			point_update(idx, val, l, mid, 2 * pos);
		else
			point_update(idx, val, mid + 1, r, 2 * pos + 1);
		tree_[pos] = merge(tree_[2 * pos], tree_[2 * pos + 1]);
	}

private:
	node merge(const node& l, const node& r) {
		node ret;
		ret.range_min = min(l.range_min, r.range_min);
		return ret;
	}

	vector<node> tree_;
	int n_;
};

int main() {
	int n, q;
	cin >> n >> q;
	SegmentTree st(n);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		st.point_update(i, x, 1, n);
	}
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << st.range_query(l, r, 1, n).range_min << "\n";
	}
	return 0;
}