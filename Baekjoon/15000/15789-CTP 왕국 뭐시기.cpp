#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
bool visit[100005] = {};

bool cmp(const int &a, const int &b) {
	return a > b;
}

int dfs(int root) {
	int cnt = 1;
	visit[root] = true;
	for (int i = 0;i < v[root].size();i++) {
		if (!visit[v[root][i]])
			cnt += dfs(v[root][i]);
	}

	return cnt;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, x, y, c, h, k;
	vector<int> power;
	cin >> n >> m;
	v.resize(n+1);
	for (int i = 0;i < m;i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	cin >> c >> h >> k;
	int cnt = dfs(c);
	dfs(h);
	for (int i = 1;i <= n;i++) {
		if (!visit[i]) {
			power.push_back(dfs(i));
		}
	}

	sort(power.begin(), power.end(), cmp);

	for (int i = 0;i < power.size() && k>0;i++, k--) {
		cnt += power[i];
	}

	cout << cnt;

	return 0;
}