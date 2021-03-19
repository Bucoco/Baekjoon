#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	long long int s=1, e=0, mid;
	cin >> n >> m;
	vector<long long int> v(n);
	for (auto &i : v) {
		cin >> i;
		if (e < i)
			e = i;
	}

	long long int cnt, result = 0;
	while (s <= e) {
		cnt = 0;
		mid = (s + e) / 2;
		for (auto &i : v) {
			if(mid<i)
				cnt += i-mid;

		}
		if (cnt >= m) {
			result = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	cout << result;

	return 0;
}