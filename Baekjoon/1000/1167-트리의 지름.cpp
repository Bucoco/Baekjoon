#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<int, int>>> tree;
bool visit[100005] = {};
int n;

pair<int, int> dfs(int root, int d) {
	visit[root] = true;
	pair<int, int> ret = { root, d };
	pair<int, int> temp = {};
	for (auto i : tree[root]) {
		if (!visit[i.first]) {
			visit[i.first] = true;
			temp = dfs(i.first, i.second + d);
			if (ret.second < temp.second)
				ret = temp;
		}
	}
	return ret;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> n;
	tree.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (true) {
			cin >> b;
			if (b == -1)
				break;
			cin >> c;
			tree[a].push_back({ b,c });
		}
	}

	pair<int, int> v1 = dfs(1, 0);
	fill(visit,visit + 100005, false);
	pair<int, int> v2 = dfs(v1.first, 0);

	cout << v2.second;
	return 0;
}