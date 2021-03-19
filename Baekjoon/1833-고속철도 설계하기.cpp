#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[205] = {};
int cost = 0;

struct Edge {
	int s;
	int e;
	int value;
};

vector<Edge> res;


bool cmp(Edge a, Edge b) {
	if (a.value == b.value) {
		if (a.s == b.s) {
			return a.e < b.e;
		}
		return a.s < b.s;
	}
	return a.value < b.value;
}

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

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[y] = x;
	}
}

void Union2(Edge edge) {
	int x = Find(edge.s);
	int y = Find(edge.e);
	if (x != y) {
		parent[y] = x;
		cost += edge.value;
		res.push_back(edge);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector<Edge> v;
	bool visit[205][205] = {};
	int n, a;

	cin >> n;
	for (int i = 0;i < n;i++) {
		parent[i] = i;
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a;
			if (a > 0) {
				v.push_back({ i,j,a });
			}
			else if (a < 0) {
				if (!visit[i][j]) {
					Union(i, j);
					cost += a * -1;
					visit[i][j] = true;
					visit[j][i] = true;
				}
			}
		}
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		Union2(i);
	}

	cout << cost << ' ' << res.size() << '\n';
	for (auto i : res) {
		cout << i.s + 1 << ' ' << i.e + 1 << '\n';
	}

	return 0;
}