#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n + 1);
	vector<int> indegree(n + 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int root = q.front();
		q.pop();
		cout << root << ' ';
		for (int i : v[root]) {
			indegree[i]--;
			if (indegree[i] == 0)
				q.push(i);
		}
	}

	return 0;
}