#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int parent[1005] = {};
int cost = 0, cnt = 0;
vector<pair<int, int>> v;

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		int y = Find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void Union(int x, int y, int c) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
		cnt++;
		cost += c;
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	bool visit[205][205] = {};
	int n, m, k;

	cin >> n >> m >> k;
	

	int a, b;
	for (int i = 0;i < m;i++) {
		cin >> a >> b;
		v.push_back({a, b});
	}

	for (int i = 0;i < k;i++) {
		cnt = 0;
		cost = 0;
		for (int t = 0;t <= n;t++) {
			parent[t] = t;
		}
		for (int j = i;j < m;j++) {
			Union(v[j].first, v[j].second, j + 1);
		}
		if (cnt == n - 1)
			cout << cost << ' ';
		else
			cout << 0 <<' ';
	}

	return 0;
}
