#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	
	if (n >= m + k - 1 && n <= m * k) {
		for (int i = 0;i < n;i++)
			v[i] = i + 1;
		int s = 0, e = k;
		reverse(v.begin(), v.begin() + e);
		n -= k;
		m--;
		while (m) {
			s = e;
			e += n / m;
			n -= n / m;
			m--;
			reverse(v.begin() + s, v.begin() + e);
		}
		for (auto &i : v)
			cout << i << " ";
	}
	else {
		cout << -1;
	}

	return 0;
}