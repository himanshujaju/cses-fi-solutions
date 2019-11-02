#include <bits/stdc++.h>
using namespace std;

namespace interval_tree_2d {

/**
* 2D FenwickTree data structure to solve range query problems.
* The constructor takes in input `N` - the number of rows and `M` - the number of columns.
* The tree is formed for (x, y) where x is in range [1, N] and y is in range [1, M]
* and can only serve queries in this range.
* Note: FenwickTree is only available for integral data types.
*
* Query runs in O(log^2N).
* Update runs in O(log^2N).
*
* For example, interval_tree_2d::FenwickTree<int> rangeTree(100, 90);
* 
* Author: Himanshu Jaju
*/

template<typename T>
class FenwickTree {
public:
  FenwickTree(int N, int M) : N_(N), M_(M) {
    static_assert(std::is_integral<T>::value, "Only defined for integral types");
    int nodes = (N_ + 1) * (M_ + 1);
    tree_.resize(nodes);
  }

  // Resizes the tree, no guarantees for existing information.
  void Resize(int N, int M) {
    N_ = N;
    M_ = M;
    int nodes = (N_ + 1) * (M_ + 1);
    tree_.resize(nodes);
  }

  // Clears the tree
  void Clear() {
    N_ = M_ = 0;
    tree_.clear();
  }

  // Adds `add_value` to position (`x`, `y`) in 2d tree.
  void PointUpdate(int x, int y, T add_value) {
    assert(x > 0 && x <= N_);
    assert(y > 0 && y <= M_);

    for (; x <= N_; x += (x & -x)) {
      int actual_index = x * (M_ + 1);
      for (int temp_y = y; temp_y <= M_; temp_y += (temp_y & -temp_y)) {
        tree_[actual_index + temp_y] += add_value;
      }
    }
  }

  // Returns the prefix sum in range ([1 ... `x`], [1 ... `y`])
  T PrefixSum(int x, int y) const {
    assert(x >= 0 && x <= N_);
    assert(y >= 0 && y <= M_);

    T ret = 0;
    for (; x > 0; x -= (x & -x)) {
      int actual_index = x * (M_ + 1);
      for (int temp_y = y; temp_y > 0; temp_y -= (temp_y & -temp_y)) {
        ret += tree_[actual_index + temp_y];
      }
    }
    return ret;
  }

  // Return the sum in sub-rectangle [(x1, y1) ... (x2, y2)]
  T RangeQuery(int x1, int y1, int x2, int y2) const {
    assert(x1 <= x2 && y1 <= y2);
    return PrefixSum(x2, y2) + PrefixSum(x1 - 1, y1 - 1)
          - PrefixSum(x2, y1 - 1) - PrefixSum(x1 - 1, y2);
  }

private:
  vector<T> tree_;
  int N_, M_;
};

} // namespace interval_tree_2d

constexpr int maxn = 1010;
int v[maxn][maxn];

int main() {
	int n, q;
	cin >> n >> q;
	interval_tree_2d::FenwickTree<int> rangeTree(n, n);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= n; j++)
			v[i][j] = (s[j - 1] == '*');
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			rangeTree.PointUpdate(i, j, v[i][j]);

	while(q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << rangeTree.RangeQuery(x1, y1, x2, y2) << "\n";
	}
	return 0;
}