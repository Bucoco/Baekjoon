#include <iostream>
#include <vector>
using namespace std;

int parent[55] = {};
bool truth[55] = {};

int find(int x) {
	if (x == parent[x]) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (truth[x])
		truth[y] = true;
	parent[x] = y;
	
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, a, b, ans = 0;
	int party[55] = {};

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;

	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b;
		truth[b] = true;
	}

	ans = m;
	for (int i = 0; i < m; i++) {
		cin >> a;
		int pre = 0;
		for (int i = 0; i < a; i++) {
			cin >> b;
			if (!pre)
				pre = b;
			else
				merge(pre, b);
		}
		party[i] = b;
	}

	for (int i = 0; i < m; i++) {
		if (truth[find(party[i])])
			ans--;
	}

	cout << ans;

	return 0;
}