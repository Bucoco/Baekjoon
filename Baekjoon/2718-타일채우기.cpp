#include <iostream>
using namespace std;

int main() {
	int t, n;
	int dp[1000][5] = {};
	cin >> t;

	dp[0][0] = 1;
	dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = 1;
	int cur = 2;
	while (t--) {
		cin >> n;
		if (!dp[n][0]) {
			for (int i = cur;i <= n;i++) {
				dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3] + dp[i - 2][0];
				dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
				dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
				dp[i][3] = dp[i - 1][0] + dp[i - 1][4];
				dp[i][4] = dp[i - 1][3];
			}
			cur = n;
		}
		cout << dp[n][0] << "\n";

	}
	return 0;
}