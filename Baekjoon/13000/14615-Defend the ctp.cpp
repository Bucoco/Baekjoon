#include <iostream>
#include <vector>
using namespace std;

bool visit1[100005] = {};
bool visit2[100005] = {};
vector<vector<int>> graph;
vector<vector<int>> rgraph;

void dfs1(int root) {
	visit1[root] = true;
	for (auto &i : graph[root]) {
		if (!visit1[i]) {
			dfs1(i);
		}
	}
}

void dfs2(int root) {
	visit2[root] = true;
	for (auto &i : rgraph[root]) {
		if (!visit2[i]) {
			dfs2(i);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, t, c, a, b;
	cin >> n >> m;
	graph.resize(n + 1);
	rgraph.resize(n + 1);
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}
	dfs1(1);
	dfs2(n);
	cin >> t;
	for (int i = 0;i < t;i++) {
		cin >> c;
		if (visit1[c] && visit2[c]) {
			cout << "Defend the CTP\n";
		}
		else {
			cout << "Destroyed the CTP\n";
		}
	}

	return 0;
}