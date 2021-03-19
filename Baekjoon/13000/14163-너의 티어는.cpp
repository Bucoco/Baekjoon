#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	double w, l, d;
	double dp[21][41] = {};
	cin >> w >> l >> d;

	dp[0][20] = 1.0;
	for (int i = 1;i < 21;i++) {
		for (int j = 0;j < 41;j++) {
			if (dp[i - 1][j] == 0) continue;
			if (j > 0)
				dp[i][j - 1] += dp[i - 1][j] * l;
			dp[i][j] += dp[i - 1][j] * d;
			if (j < 41)
				dp[i][j + 1] += dp[i - 1][j] * w;
		}
	}
	double sum = 0;
	cout << fixed;
	cout.precision(8);
	for (int i = 0;i < 40;i += 10) {
		sum = 0;
		for (int j = 0;j < 10;j++) {
			sum += dp[20][i + j];
		}
		
		cout << sum << "\n";
	}
	cout << dp[20][40];

	return 0;
}