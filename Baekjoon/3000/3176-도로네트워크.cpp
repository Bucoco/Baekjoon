#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

vector<vector<pair<int,int>>> g;
int parent[100010][21] = {};
int lroad[100010][21] = {}, sroad[100010][21] = {};
int depth[100010] = {};
bool visit[100010] = {};
int a, b, c, n, k;


void dfs(int cur, int d) {
	visit[cur] = true;
	depth[cur] = d;
	for (auto &i : g[cur]) {
		if (!visit[i.first]) {
			dfs(i.first, d + 1);
			parent[i.first][0] = cur;
			lroad[i.first][0] = i.second;
			sroad[i.first][0] = i.second;
		}
	}
}

void findParent() {
	for (int i = 1;i <= log(n);i++) {
		for (int j = 1;j <= n;j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			lroad[j][i] = max(lroad[j][i - 1], lroad[parent[j][i - 1]][i - 1]);
			if (sroad[parent[j][i - 1]][i - 1]) {
				sroad[j][i] = min(sroad[j][i - 1], sroad[parent[j][i - 1]][i - 1]);
			}
		}
	}
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	g.resize(n + 1);
	for (int i = 0;i < n - 1;i++) {
		cin >> a >> b >> c;
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	dfs(1, 1);
	findParent();
	cin >> k;
	int d, e;
	int index = 0;
	for (int i = 0;i < k;i++) {
		cin >> a >> b;
		int res1 = 0, res2 = 1000001;
		d = a;
		e = b;
		while (depth[a] > depth[b]) {
			index = 0;
			while (depth[parent[a][index]] >= depth[b]) {
				index++;
			}
			res1 = max(res1, lroad[a][index - 1]);
			res2 = min(res2, sroad[a][index - 1]);
			a = parent[a][index - 1];

		}

		while (depth[a] < depth[b]) {
			index = 0;
			while (depth[parent[b][index]] >= depth[a]) {
				index++;
			}
			res1 = max(res1, lroad[b][index - 1]);
			res2 = min(res2, sroad[b][index - 1]);
			b = parent[b][index - 1];
		}
		while (a != b) {
			index = 0;
			if (parent[a][index] == parent[b][index]) {
				index++;
			}
			while (parent[a][index] != parent[b][index]) {
				index++;
			}
			res1 = max(res1, max(lroad[b][index - 1], lroad[a][index - 1]));
			res2 = min(res2, min(sroad[b][index - 1], sroad[a][index - 1]));
			a = parent[a][index - 1];
			b = parent[b][index - 1];
		}
		cout << res2 << " " << res1 << "\n";
	}


	return 0;
}