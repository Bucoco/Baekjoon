#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector<vector<int>> v;
	vector<int> weight, indegree, res;
	int t, n, k, w;

	cin >> t;
	while (t--) {
		cin >> n >> k;

		v.clear();
		weight.clear();
		indegree.clear();
		res.clear();
		v.resize(n + 1);
		indegree.resize(n + 1);
		weight.resize(n + 1);
		res.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> weight[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			indegree[y]++;
		}

		cin >> w;

		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (!indegree[i]) {
				q.push(i);
				res[i] = weight[i];
			}
		}

		while (!q.empty()) {
			int root = q.front();
			q.pop();

			for (int i : v[root]) {
				indegree[i]--;
				if (res[i] < res[root] + weight[i]) {
					res[i] = res[root] + weight[i];
				}
				if (!indegree[i]) {
					q.push(i);
				}
			}
		}

		cout << res[w] << '\n';
	}

	return 0;
}