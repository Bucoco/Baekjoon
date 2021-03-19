#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, c;
	cin >> n >> c;
	vector<int> v(n);

	for (auto &i : v)
		cin >> i;

	sort(v.begin(), v.end());
	long long int s, e, mid, result=1, cnt;
	s = 1;
	e = v.back() - v.front();
	while (s <= e) {
		cnt = 1;
		mid = (s + e) / 2;

		int h=v[0];
		for (auto &i : v) {
			if (i - h >= mid) {
				cnt++;
				h = i;
			}
		}

		if (cnt >= c) {
			result = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	cout << result;

	return 0;
}