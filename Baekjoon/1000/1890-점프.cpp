#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	long long int map[105][105] = {}, dp[105][105] = {};
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			cin >> map[i][j];
	dp[0][0] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++) {
			if (!map[i][j])
				break;
			if (dp[i][j]) {
				if (i + map[i][j] < n)
					dp[i + map[i][j]][j] += dp[i][j];
				if (j + map[i][j] < n)
					dp[i][j + map[i][j]] += dp[i][j];
			}
		}
	cout << dp[n - 1][n - 1];  

	return 0;
}
