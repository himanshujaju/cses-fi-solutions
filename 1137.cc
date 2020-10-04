#include <bits/stdc++.h>
using namespace std;

namespace interval_tree_1d {

/**
* 1D FenwickTree data structure to solve range query problems.
* The constructor takes in input `N` - the number of nodes to serve.
* The tree is formed for range [1, N] and can only serve queries in this range.
* Note: FenwickTree is only available for integral data types.
*
* Query runs in O(logN).
* Update runs in O(logN).
*
* For example, interval_tree_1d::FenwickTree<int> rangeTree(100);
* 
* Author: Himanshu Jaju
*/

template<typename T>
class FenwickTree {
public:
  FenwickTree(int N) : N_(N) {
    static_assert(std::is_integral<T>::value, "Only defined for integral types");
    tree_.resize(N_ + 1);
  }

  // Resizes the tree, no guarantees for existing information.
  void Resize(int N) {
    N_ = N;
    tree_.resize(N_ + 1);
  }

  // Clears the tree
  void Clear() {
    N_ = 0;
    tree_.clear();
  }

  // Adds `add_value` to `index`
  void PointUpdate(int index, T add_value) {
    assert(index > 0 && index <= N_);
    
    for (; index <= N_; index += (index & -index)) {
      tree_[index] += add_value;
    }
  }

  // Returns the prefix sum in range [1, `index`]
  T PrefixSum(int index) const {
    assert(index >= 0 && index <= N_);

    T ret = 0;
    for (; index > 0; index -= (index & -index)) {
      ret += tree_[index];
    }
    return ret;
  }

  // Return the sum in range [`l`, `r`]
  T RangeQuery(int l, int r) const {
    assert(l > 0 && r >= l && r <= N_);
    return PrefixSum(r) - PrefixSum(l - 1);
  }

private:
  vector<T> tree_;
  int N_;
};

} // namespace interval_tree_1d

constexpr int maxn = 200001;
int current_time = 0;

int start_time[maxn], end_time[maxn];
vector<int> edges[maxn];
int val[maxn];

void dfs(int u, int p) {
	start_time[u] = ++current_time;
	for (int v: edges[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	end_time[u] = current_time;
}
 
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> val[i];

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	dfs(1, 0);

	interval_tree_1d::FenwickTree<long long> rangeTree(n);
	for (int i = 1; i <= n; i++) {
		rangeTree.PointUpdate(start_time[i], val[i]);
	}

	while(q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int s, x;
			cin >> s >> x;
			rangeTree.PointUpdate(start_time[s], x - val[s]);
			val[s] = x;
		} else {
			int s;
			cin >> s;
			cout << rangeTree.RangeQuery(start_time[s], end_time[s]) << "\n";
		}
	}
	return 0;
}