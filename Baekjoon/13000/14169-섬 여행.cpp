#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<vector<int>> v;
vector<int> h;
bool visit[103] = {};
int n, m, x, y, t, a, k;
int result;

void dfs(int r, int cnt) {
	if (cnt == k) {
		if (result > h[r])
			result = h[r];
		visit[r] = true;

		return;
	}
	for (auto &i : v[r]) {
		if (!visit[i]) {
			dfs(i, cnt + 1);
		}
	}
	visit[r] = true;
}

int main() {
	ios::sync_with_stdio(false);

	cin >> n >> m;
	h.resize(n + 1);
	v.resize(n + 1);
	for (int i = 0;i < n;i++)
		cin >> h[i + 1];
	for (int i = 0;i < m;i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin >> t;
	int r, c;
	for (int i = 0;i < t;i++) {
		result = 10001;
		memset(visit, 0, sizeof(visit));
		cin >> a >> k;
		if (v[a].empty())
			cout << "-1\n";
		else {
			for (auto &i : v[a]) {
				dfs(i, 1);
			}
			cout << result << "\n";
		}
	}

	return 0;
}