#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, a, b, c, s, d, cnt = 0;
	cin >> n >> m;
	vector<int> weight(n + 1);
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<vector<pair<int, int>>> rgraph(n + 1);
	int indegree[10005] = {};
	bool visit[10005] = {};

	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		rgraph[b].push_back(make_pair(a, c));
		indegree[b]++;
	}
	cin >> s >> d;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (auto &i : graph[tmp]) {
			weight[i.first] = max(weight[i.first], weight[tmp] + i.second);
			indegree[i.first]--;
			if (indegree[i.first] == 0)
				q.push(i.first);
		}
	}
	q.push(d);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (auto &i : rgraph[tmp]) {
			if (weight[tmp] - i.second == weight[i.first]) {
				cnt++;
				if (!visit[i.first]) {
					visit[i.first] = true;
					q.push(i.first);
				}
			}
		}
	}
	cout << weight[d] << "\n" << cnt;

	return 0;
}