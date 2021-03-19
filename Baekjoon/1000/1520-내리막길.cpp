#include <iostream>
using namespace std;

int n, m;
int map[505][505] = {}, dp[505][505] = {}, dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

int dfs(int x, int y) {
	if (dp[y][x] != -1)
		return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0;i < 4;i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[ny][nx] < map[y][x])
			dp[y][x] += dfs(nx, ny);
	}

	return dp[y][x];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	dp[n - 1][m - 1] = 1;
	
	cout << dfs(0, 0);

	return 0;
}