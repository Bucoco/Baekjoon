#include <iostream>
using namespace std;

int n, m;
int arr[505][505] = {};
bool visit[505][505] = {};
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int dx2[4][3] = { {1,2,1},{0,0,-1},{1,2,1},{0,0,1} }, dy2[4][3] = { {0,0,1},{1,2,1},{0,0,-1},{1,2,1} };
int res = 0;

void dfs(int x, int y, int c, int sum) {
	if (c > 3) {
		res = res < sum ? sum : res;
		return;
	}
	for (int i = 0;i < 4;i++) {
		int mx = x + dx[i], my = y + dy[i];
		if (mx >= 0 && mx < m && my >= 0 && my < n && !visit[my][mx]) {
			visit[my][mx] = true;
			dfs(mx, my, c + 1, sum+arr[my][mx]);
			visit[my][mx] = false;
		}
	}
}

void dfs2(int x, int y) {
	int sum = 0;
	for (int i = 0;i < 4;i++) {
		sum = arr[y][x];
		bool flag = true;
		for (int j = 0;j < 3;j++) {
			int mx = x + dx2[i][j], my = y + dy2[i][j];
			if (mx < 0 || mx >= m || my < 0 || my >= n) {
				flag = false;
				break;
			}
			sum += arr[my][mx];
		}
		if (flag) {
			res = res < sum ? sum : res;
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> arr[i][j];

	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++) {
			visit[i][j] = true;
			dfs(j, i, 1, arr[i][j]);
			visit[i][j] = false;
			dfs2(j, i);
		}

	cout << res;

	return 0;
}