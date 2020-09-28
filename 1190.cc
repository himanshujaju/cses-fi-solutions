#include <bits/stdc++.h>
using namespace std;

struct SegmentTreeNode {
	long long prefix_max = 0;
	long long suffix_max = 0;
	long long ans = 0;
	long long sum = 0;

	void init(int x) {
		ans = prefix_max = suffix_max = max(0, x);
		sum = x;
	}

	SegmentTreeNode merge(const SegmentTreeNode& rhs) {
		SegmentTreeNode ret;
		ret.sum = sum + rhs.sum;
		ret.prefix_max = max(prefix_max, sum + rhs.prefix_max);
		ret.suffix_max = max(rhs.suffix_max, suffix_max + rhs.sum);

		ret.ans = max(ans, rhs.ans);
		ret.ans = max(ret.ans, suffix_max + rhs.prefix_max);
		return ret;
	}
};

SegmentTreeNode tree[1 << 20];
int arr[1 << 20];

void init(int l, int r, int pos) {
	if (l == r) {
		tree[pos].init(arr[l]);
		return;
	}
	int mid = (l + r) >> 1;
	init(l, mid, 2 * pos);
	init(mid + 1, r, 2 * pos + 1);
	tree[pos] = tree[2 * pos].merge(tree[2 * pos + 1]);
}

void update(int index, int val, int l, int r, int pos) {
	if (l == r) {
		tree[pos].init(val);
		return;
	}

	int mid = (l + r) >> 1;
	if (index <= mid)
		update(index, val, l, mid, 2 * pos);
	else
		update(index, val, mid + 1, r, 2 * pos + 1);

	tree[pos] = tree[2 * pos].merge(tree[2 * pos + 1]);
}
 
int main() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	init(1, N, 1);
	while(Q--) {
		int x, y;
		cin >> x >> y;
		update(x, y, 1, N, 1);
		cout << tree[1].ans << "\n";
	}
	return 0;
}
