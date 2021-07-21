#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v;
vector<int> indegree;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	indegree.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		vector<int> temp(num);
		for (auto &j:temp) {
			cin >> j;
		}

		for (int j = 0; j < num - 1; j++) {
			v[temp[j]].push_back(temp[j + 1]);
			indegree[temp[j + 1]]++;
		}
	}

	queue<int> q;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) 
			q.push(i);
	}

	while (!q.empty()) {
		int root = q.front();
		q.pop();
		for (int i : v[root]) {
			indegree[i]--;
			if (!indegree[i])
				q.push(i);
		}
		ans.push_back(root);
	}

	if (ans.size() < n)
		cout << 0;
	else
		for (int i : ans)
			cout << i << '\n';

	return 0;
}