#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define INF 200000000

vector<vector<pair<int, int>>> edge;
int dist[20005] = {};

void dijkstra(int root) {
	dist[root] = 0;
	priority_queue <pair<int, int>> pq;
	pq.push({ 0,root });
	while (!pq.empty()) {
		int weight = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < weight)
			continue;
		for (auto i : edge[cur]) {
			int next_w = weight + i.first;
			int next = i.second;

			if (dist[next] > next_w) {
				dist[next] = next_w;
				pq.push({ -next_w,next });
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int V, E, start, u, v, w;
	cin >> V >> E >> start;

	fill(dist, dist + V + 1, INF);
	edge.resize(V + 1);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		edge[u].push_back({ w,v });
	}

	dijkstra(start);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}

	return 0;
}