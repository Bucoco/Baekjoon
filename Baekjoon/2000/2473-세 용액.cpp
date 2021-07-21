#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	vector<long long> v(n);

	for (auto &i : v) {
		cin >> i;
	}

	sort(v.begin(), v.end());

	long long ans[3]{};
	long long sum = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		int l = i + 1, r = n - 1;
		while (l < r) {
			if (abs(sum) > abs(v[i] + v[l] + v[r])) {
				ans[0] = v[i];
				ans[1] = v[l];
				ans[2] = v[r];
				sum = v[i] + v[l] + v[r];
			}
			if (v[i] + v[l] + v[r] < 0) {
				l++;
			}
			else {
				r--;
			}
		}
	}

	for (auto i : ans)
		cout << i << ' ';

	return 0;
}