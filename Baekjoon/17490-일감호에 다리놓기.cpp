#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	long long k, sum = 0;
	vector<pair<int,int>> v;
	vector<int> w;

	cin >> n >> m >> k;
	w.resize(n + 1);

	for (int i = 1;i <= n;i++)
		cin >> w[i];

	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		if (a != n && a > b)
			swap(a, b);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	if (m <= 1) {
		cout << "YES";
	}
	else {
		int s, e, Min = 1000001;
		s = v.back().second;
		e = v.front().first;
		while (1) {
			Min = min(Min, w[s]);
			if (s == e)
				break;
			s = s % n + 1;
		}

		sum += Min;
		for (int i = 0;i < m - 1;i++) {
			Min = 1000001;
			s = v[i].second;
			e = v[i + 1].first;
			while (1) {
				Min = min(Min, w[s]);
				if (s == e)
					break;
				s = s % n + 1;
			}
			sum += Min;
		}
		if (k < sum)
			cout << "NO";
		else
			cout << "YES";
	}

	return 0;
}