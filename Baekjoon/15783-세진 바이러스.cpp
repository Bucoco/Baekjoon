#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector<vector<int>> graph;
vector<vector<int>> rgraph;
vector<int> sccnum;
vector<int> indegree;
vector<int> st;
int visit[100000] = {};
int num = 0;

void dfs(int cur) {
	if (visit[cur])
		return;
	visit[cur] = true;
	for (auto &i : graph[cur]) {
		dfs(i);
	}
	st.push_back(cur);
}

void dfs2(int cur) {
	if (visit[cur]) {
		if (sccnum[cur] != num) {
			indegree[num]++;
		}
		return;
	}
	visit[cur] = true;
	sccnum[cur] = num;
	for (auto &i : rgraph[cur]) {
		dfs2(i);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, a, b;

	cin >> n >> m;

	graph.resize(n);
	rgraph.resize(n);
	sccnum.resize(n);
	indegree.resize(n);

	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		rgraph[b].push_back(a);
	}

	for (int i = 0;i < n;i++) {
		if (!visit[i])
			dfs(i);
	}

	memset(visit, false, sizeof(visit));
	int top;
	while (!st.empty()) {
		top = st.back();
		st.pop_back();
		
		dfs2(top);
		num++;
	}

	int cnt = 0;
	for (auto &i : indegree) {
		if (!i)
			cnt++;
	}

	cout << cnt;
	return 0;
}