#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxLog = 30;
constexpr int kMaxN = 200000;
constexpr int kRoot = 0;

int trie[kMaxN * kMaxLog][2];
int last_used_node = 0;

vector<int> get_bits(int v) {
	vector<int> bits;
	for (int i = 0; i < kMaxLog; i++) {
		bits.push_back(v&1);
		v /= 2;
	}
	reverse(bits.begin(), bits.end());
	return bits;
}

void add_num(int v) {
	vector<int> bits = get_bits(v);

	int node = 0;
	for (int x: bits) {
		if (!trie[node][x])
			trie[node][x] = ++last_used_node;
		node = trie[node][x];
	}
}

int get_best_xor(int v) {
	vector<int> bits = get_bits(v);

	int multiplier = 1;
	for (int i = 1; i <= kMaxLog; i++) {
		multiplier *= 2;
	}

	int ret = 0;
	int node = kRoot;
	for (int x: bits) {
		multiplier /= 2;

		int next_bit = x ^ 1;
		if (!trie[node][next_bit])
			next_bit = x;

		ret += ((next_bit ^ x) * multiplier);
		node = trie[node][next_bit];
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	int prefix_xor = 0;
	add_num(prefix_xor);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		prefix_xor ^= v;
		add_num(prefix_xor);
		ans = max(ans, get_best_xor(prefix_xor));
	}

	cout << ans << "\n";
	return 0;
}
