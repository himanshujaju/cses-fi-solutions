#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 10000000;
 
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

class SegmentTree {
public:
	SegmentTree() {
		tree.resize(1 << 20);
	}

	~SegmentTree() {}

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

int GetMax() {
	return tree[1].ans;
}

private:
	vector<SegmentTreeNode> tree;
};

SegmentTree st[2];
int arr[1 << 20];
 
int main() {
	string s;
	cin >> s;
	int N = s.size();
	for (int i = 1; i <= N; i++) {
		int val = (int)(s[i - 1] - '0');
		st[val].update(i, 1, 1, N, 1);
		st[!val].update(i, -inf, 1, N, 1);
		arr[i] = val;
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int pos;
		cin >> pos;

		arr[pos] ^= 1;
		int val = arr[pos];
		st[val].update(pos, 1, 1, N, 1);
		st[!val].update(pos, -inf, 1, N, 1);

		cout << max(st[0].GetMax(), st[1].GetMax()) << " ";
	}
	cout << "\n";
	return 0;
}