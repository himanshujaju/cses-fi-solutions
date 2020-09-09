#include <bits/stdc++.h>
using namespace std;

/**
Supports - Add element / Remove element / Find Median operations.
*/
class RunningMedian {
public:
	void AddElement(int v) {
		items_ += 1;
		auto it = right_half_.begin();
		if (it == right_half_.end() || v <= *it) {
			left_half_.insert(v);
			sum_left_half_ += v;
		}
		else {
			right_half_.insert(v);
			sum_right_half_ += v;
		}
		ReBalance();
	}

	void RemoveElement(int v) {
		items_ -= 1;
		auto it = left_half_.find(v);
		if (it != left_half_.end()) {
			left_half_.erase(it);
			sum_left_half_ -= v;
		}
		else {
			it = right_half_.find(v);
			right_half_.erase(it);
			sum_right_half_ -= v;
		}
		ReBalance();
	}

	long long GetCost() {
		assert(items_ > 0);

		auto it = left_half_.rbegin();
		int median = *it;

		long long lhs_cost = 1LL * ((items_ + 1) / 2) * median - sum_left_half_;
		long long rhs_cost = sum_right_half_ - 1LL * (items_ / 2) * median;
		return lhs_cost + rhs_cost;
	}

private:
	void ReBalance() {
		int reqd_left_size = (items_ + 1) / 2;
		
		while (left_half_.size() < reqd_left_size) {
			auto it = right_half_.begin();
			int v = *it;
			left_half_.insert(v);
			sum_left_half_ += v;
			right_half_.erase(it);
			sum_right_half_ -= v;
		}

		while (left_half_.size() > reqd_left_size) {
			auto it = left_half_.end();
			it--;
			int v = *it;
			right_half_.insert(v);
			sum_right_half_ += v;
			left_half_.erase(it);
			sum_left_half_ -= v;
		}
	}

	// |left_half_| contains the ceil(|items_|/2) elements, and the rest are
	// in |right_half_|.
	multiset<int> left_half_, right_half_;
	long long sum_left_half_ = 0, sum_right_half_ = 0;
	int items_ = 0;
};
 
int main() {
	RunningMedian running_median;
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int &x: arr)
		cin >> x;

	for (int i = 0; i < k; i++)
		running_median.AddElement(arr[i]);

	cout << running_median.GetCost() << " ";
	for (int i = k; i < n; i++) {
		running_median.RemoveElement(arr[i - k]);
		running_median.AddElement(arr[i]);
		cout << running_median.GetCost() << " ";
	}
	cout << "\n";
	return 0;
}