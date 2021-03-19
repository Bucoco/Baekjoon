#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int k, n;
	cin >> k >> n;
	vector<int> v(k);
	for (auto &i : v)
		cin >> i;

	sort(v.begin(), v.end());
	long long int cnt, s = 1, e = v.back(), mid, result;
	while (s<=e)
	{
		cnt = 0;
		mid = (s + e) / 2;
		for (auto &i : v) {
			cnt += i / mid;
		}
		if (cnt >= n) {
			result = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	cout << result;
	return 0;
}