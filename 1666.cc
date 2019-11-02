#include <bits/stdc++.h>
using namespace std;

namespace graph {

/**
* Disjoint Set Union is used to solve problems where edge(u,v) denote union of
* set u and set v.
*
* Build time : O(N)
* AddEdge : O(log* N)
* GetParent : O(log* N)
* GetSize : O(log* N)
*
* Author: Himanshu Jaju
*/

class DisjointSetUnion {
public:
  DisjointSetUnion(int N) : N_(N) {
    par_.resize(N_ + 1);
    size_.resize(N_ + 1);
    for (int i = 0; i <= N_; i++) {
      size_[i] = 1;
      par_[i] = i;
    }
  }

  // Returns the parent of |x|'s set.
  int GetParent(int x) {
    if (par_[x] != x) {
      par_[x] = GetParent(par_[x]);
    }
    return par_[x];
  }

  // Returns the size of set in which |x| belongs.
  int GetSize(int x) {
    return size_[GetParent(x)];
  }

  // Add an edge between |u| and |v|. Creates union of both sets.
  void AddEdge(int u, int v) {
    int parent_u = GetParent(u);
    int parent_v = GetParent(v);
    if (parent_u != parent_v) {
      if (size_[parent_v] > size_[parent_u]) {
        swap(parent_u, parent_v);
      }
      par_[parent_v] = parent_u;
      size_[parent_u] += size_[parent_v];
      size_[parent_v] = 0;
    }
  }

private:
  int N_;
  vector<int> par_, size_;
};

} // namespace graph

int main() {
	int N, M;
	cin >> N >> M;
	graph::DisjointSetUnion dsu(N);
	while(M--) {
		int u, v;
		cin >> u >> v;
		dsu.AddEdge(u, v);
	}
	vector<int> arr;
	for (int i = 1; i <= N; i++) {
		if (dsu.GetParent(i) == i)
			arr.push_back(i);
	}
	int sz = arr.size();
	cout << sz - 1 << "\n";
	for (int i = 1; i < sz; i++)
		cout << arr[i - 1] << " " << arr[i] << "\n";
	return 0;
}