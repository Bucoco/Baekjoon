#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int dp[1001] = {};
	int n;

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3;i <= n;i++) {
		dp[i] = dp[i - 1] % 10007 + dp[i - 2] % 10007;
		dp[i] %= 10007;
	}

	cout << dp[n];
	return 0;
}