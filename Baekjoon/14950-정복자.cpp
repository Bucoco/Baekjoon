#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
using namespace std;


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector<vector<pair<int,int>>> v;
	priority_queue <pair <int, int>, vector <pair <int, int>>, greater<pair <int, int>>> pq;
	bool visit[10010] = {};
	int n, m, t, ans = 0, turn = 0;

	cin >> n >> m >> t;
	v.resize(n + 1);
	int a, b, c;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		v[a].push_back({ c, b });
		v[b].push_back({ c, a });
	}

	for (auto i:v[1]) {
		pq.push(i);
	}
	visit[1] = true;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cur_cost = pq.top().first;

		pq.pop();

		if (!visit[cur]) {
			visit[cur] = true;

			for (auto i:v[cur])
			{
				pq.push(i);
			}
			ans += cur_cost + (t*turn);
			turn++;
		}
	}

	cout << ans;

	return 0;
}