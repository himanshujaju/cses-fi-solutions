#include <bits/stdc++.h>
using namespace std;
 
struct node {
	int range_max;
	
	node() {
		range_max = 0;
	}
};
 
class SegmentTree {
public:
	SegmentTree(int n) : n_(n) {
		tree_.resize(4 * n_);
	}
	~SegmentTree() = default;
 
	int GetPos(int reqd, int l, int r, int pos = 1) {
		if (tree_[pos].range_max < reqd) return 0;
		if (l == r) return l;

		int mid = (l + r) / 2;
		if (tree_[2 * pos].range_max >= reqd)
			return GetPos(reqd, l, mid, 2 * pos);
		else
			return GetPos(reqd, mid + 1, r, 2 * pos + 1);
	}
 
	void point_update(int idx, int val, int l, int r, int pos = 1) {
		if (l == r) {
			tree_[pos].range_max = val;
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
		ret.range_max = max(l.range_max, r.range_max);
		return ret;
	}
 
	vector<node> tree_;
	int n_;
};
 
int main() {
	int n, q;
	cin >> n >> q;
	SegmentTree st(n);
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		st.point_update(i, arr[i], 1, n);
	}
	while(q--) {
		int x;
		cin >> x;
		int v = st.GetPos(x, 1, n);
		cout << v << " ";
		if (v) {
			arr[v] -= x;
			st.point_update(v, arr[v], 1, n);
		}
	}
	return 0;
}