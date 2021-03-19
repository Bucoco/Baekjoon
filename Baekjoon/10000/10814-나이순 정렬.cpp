#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
	if (a.first >= b.first)
		return false;

	return a.first < b.first;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, string>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (auto i : v)
		cout << i.first << ' ' << i.second << '\n';

	return 0;
}