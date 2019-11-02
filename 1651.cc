#include <bits/stdc++.h>
using namespace std;

struct node {
	long long range_sum;
	
	node() {
		range_sum = 0;
	}

	node(long long val) {
		range_sum = val;
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
			tree_[pos].range_sum += val;
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
		ret.range_sum = l.range_sum + r.range_sum;
		return ret;
	}

	vector<node> tree_;
	int n_;
};

int main() {
	int n, q;
	cin >> n >> q;
	vector<long long> arr(n+1);
	SegmentTree st(n);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	while(q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, b, u;
			cin >> a >> b >> u;
			st.point_update(a, u, 1, n);
			if (b != n)
				st.point_update(b + 1, -u, 1, n);
		} else {
			int k;
			cin >> k;
			long long ans = arr[k] + st.range_query(1, k, 1, n).range_sum;
			cout << ans << "\n";
		}
	}
	return 0;
}