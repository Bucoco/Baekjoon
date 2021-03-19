#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, mode = 0;
	double sum = 0;
	cin >> n;
	vector<int> v(n);
	int visit[8050] = {};
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	for (auto i : v) {
		visit[i + 4000]++;
		sum += i;
	}

	bool flag = false;
	for (int i = 1; i < 8001; i++) {
		if (visit[mode] < visit[i]) {
			flag = false;
			mode = i;
		}
		else if (visit[mode] == visit[i] && !flag) {
			flag = true;
			mode = i;
		}
	}

	cout << (int)round(sum/n) << '\n';
	cout << v[n / 2] << '\n';
	cout << mode - 4000 << '\n';
	cout << v.back() - v.front();

	return 0;
}