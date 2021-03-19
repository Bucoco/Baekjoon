#include <iostream>
using namespace std;

int n, m;
int parent[210] = {};

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

	
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		parent[i] = i;

	int a;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cin >> a;
			if (a)
				merge(i, j);
		}
	}
	
	cin >> a;
	int tmp = find(a);
	bool res = true;
	for (int i = 0;i < m - 1;i++) {
		cin >> a;
		if (tmp != find(a)) {
			res = false;
			break;
		}
	}
	if (res)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}