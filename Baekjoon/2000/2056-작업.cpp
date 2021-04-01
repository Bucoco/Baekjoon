#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	vector<int> indegree(n + 1), weight(n + 1), res(n + 1);

	for (int i = 1; i <= n; i++) {
		int childs;
		cin >> weight[i] >> childs;
		for (int j = 0; j < childs; j++) {
			int child_num;
			cin >> child_num;
			v[i].push_back(child_num);
			indegree[child_num]++;
		}
	}

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
			if (!indegree[i])
				q.push(i);
			if (res[i] < res[root] + weight[i])
				res[i] = res[root] + weight[i];
		}
	}

	int ans = 0;
	for (int i : res)
		if (ans < i)
			ans = i;

	cout << ans;

	return 0;
}