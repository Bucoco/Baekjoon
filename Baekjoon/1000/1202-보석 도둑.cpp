#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	vector<int> bag;
	vector<pair<int, int>> jewel;
	priority_queue<int> pq;


	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v;
		cin >> m >> v;
		jewel.push_back({ m, v });
	}

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		bag.push_back(c);
	}

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	long long sum = 0;

	int j = 0;
	for (int i = 0; i < k; i++) {
		while (j < n && jewel[j].first <= bag[i]) {
			pq.push(jewel[j].second);
			j++;
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}