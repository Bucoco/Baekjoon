#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	int map[1010][1010] = {}, dp[1010][1010] = {};
	cin >> n >> m;
	for (int i = 0;i < n;i++) 
		for (int j = 0;j < m;j++)
			cin >> map[i][j];
	
	dp[0][0] = map[0][0];
	int dx[] = { 1,0,1 }, dy[] = { 0,1,1 };
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			for (int k = 0;k < 3;k++) {
				int my = i + dy[k], mx = j + dx[k];
				if (my < n && mx < m) {
					dp[my][mx] = max(dp[my][mx], dp[i][j] + map[my][mx]);
				}
			}
		}
	}

	cout << dp[n - 1][m - 1];

	return 0;
}