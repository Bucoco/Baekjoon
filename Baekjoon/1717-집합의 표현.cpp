#include <iostream>
using namespace std;

int parent[1000010] = {};

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return;

	parent[u] = v;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 0;i <= n;i++) {
		parent[i] = i;
	}
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		if (!a) {
			merge(b, c);
		}
		else {
			if (find(b) == find(c))
				cout << "YES\n";
			else {
				cout << "NO\n";
			}
		}
	}

	return 0;
}