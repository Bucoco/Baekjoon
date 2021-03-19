#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> depth;
vector<vector<int>>  parent;
bool visit[100010] = {};
int n, m;

void dfs(int cur, int d) {
	visit[cur] = true;
	depth[cur] = d;
	for (auto &i : tree[cur]) {
		if (!visit[i]) {
			dfs(i, d + 1);
			parent[i][0] = cur;
		}
	}
}

void findParent() {
	for (int i = 1;i < 20;i++) {
		for (int j = 1;j <= n;j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	tree.resize(n + 1);
	parent.resize(n + 1);
	depth.resize(n + 1);

	int a, b;
	for (int i = 0;i < n - 1;i++) {
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (auto &i : parent)
		i.resize(21);
	dfs(1, 1);
	findParent();
	cin >> m;
	int index = 0;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		while (depth[a] > depth[b]) {
			index = 0;
			while (depth[parent[a][index]] >= depth[b]) {
				index++;
			}
			a = parent[a][index - 1];
		}
		while (depth[a] < depth[b]) {
			index = 0;
			while (depth[parent[b][index]] >= depth[a]) {
				index++;
			}
			b = parent[b][index - 1];
		}
		while (a != b) {
			index = 0;
			if (parent[a][index] == parent[b][index]) {
				a = parent[a][index];
				break;
			}
			while (parent[a][index] != parent[b][index]) {
				index++;
			}
			a = parent[a][index - 1];
			b = parent[b][index - 1];
		}
		cout << a << "\n";
	}

	return 0;
}