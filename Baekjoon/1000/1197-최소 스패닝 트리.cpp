#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	bool visit[10005]{};
	int n, m, a, b, c, ans = 0;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}

	priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

	pq.push(make_pair(0, 1));

	while (!pq.empty())
	{
		auto root = pq.top();
		pq.pop();

		if (visit[root.second])
			continue;
		visit[root.second] = true;

		for (auto i : v[root.second]) {
			pq.push(i);
		}

		ans += root.first;
	}

	cout << ans;

	return 0;
}