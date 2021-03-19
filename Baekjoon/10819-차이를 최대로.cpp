#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int abs(int a) {
	if (a < 0)
		return -1 * a;
	return a;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, a, res = 0;
	cin >> n;
	vector<int> v(n);
	for (int &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	do {
		int sum = 0;
		for (int i = 0;i < n - 1;i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		res = sum > res ? sum : res;
	} while (next_permutation(v.begin(), v.end()));

	cout << res;

	return 0;
}