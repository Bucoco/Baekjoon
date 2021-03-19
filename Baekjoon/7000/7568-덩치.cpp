#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector<pair<int, int>> v;
	vector<int> ans;
	int x, y, n;

	cin >> n;
	v.resize(n);
	ans.resize(n);

	for (auto& i : v) {
		cin >> i.first >> i.second;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				ans[i]++;
		}
	}

	for (int i : ans)
		cout << i + 1 << ' ';

	return 0;
}