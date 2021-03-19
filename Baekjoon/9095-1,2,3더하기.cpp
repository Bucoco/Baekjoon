#include <iostream>
using namespace std;

int main() {
	int t, n;
	int dp[11] = {};
	dp[0] = 1; dp[1] = 2; dp[2] = 4;
	for (int i = 3;i < 11;i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	cin >> t;
	for (int i = 0;i < t;i++) {
		cin >> n;
		cout << dp[n - 1] << "\n";
	}
	return 0;
}