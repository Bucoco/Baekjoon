#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k, cnt = 0;
	cin >> n >> k;
	vector<int> v;
	vector<int> w(n);
	for (int i = 0;i < n;i++) {
		v.push_back(i);
		cin >> w[i];
	}

	do {
		int a = 0;
		for (int i = 0;i < n;i++) {
			a = a + w[v[i]] - k;
			if (a < 0)
				break;
		}
		if (a < 0)
			continue;
		cnt++;

	} while (next_permutation(v.begin(), v.end()));

	cout << cnt;

	return 0;
}