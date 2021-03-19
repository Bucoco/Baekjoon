#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

vector<vector<pair<int, int>>> v;
int s, e;
bool visit[100005] = {};

bool bfs(int weight) {
	queue<int> q;
	int tmp;
	q.push(s);
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		visit[tmp] = true;
		if (tmp == e) {
			return true;
		}
		for (auto &i : v[tmp]) {
			if (!visit[i.first] && i.second >= weight) {
				q.push(i.first);
				visit[i.first] = true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, a, b, c;
	int l = 1, r = 0, mid, result = 1;

	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
		if (r < c)
			r = c;
	}

	cin >> s >> e;
	while (l <= r) {
		memset(visit, 0, sizeof(visit));
		mid = (l + r) / 2;
		if (bfs(mid)) {
			if (result < mid)
				result = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}

	}
	cout << r;
	return 0;
}