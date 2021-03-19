#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	int cost[1001][3] = {};
	int dp[1001][3] = {};

	cin >> n;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < 3;j++)
			cin >> cost[i][j];
	}
	
	for (int i = 1;i <= n;i++) {
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
	return 0;
}