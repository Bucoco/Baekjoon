#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, x, y;
	vector<pair<int, int>> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ y, x });
	}

	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i.second << ' ' << i.first << '\n';

	return 0;
}