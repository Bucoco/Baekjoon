#include <iostream>
using namespace std;

int main() {
	int x;
	int* dp;
	cin >> x;

	dp = new int[x+1];
	dp[0] = dp[1] = 0;
	for (int i = 2;i <= x;i++) {
		int min;
		min = dp[i - 1] + 1;
		if (i % 3 == 0 && (dp[i / 3] + 1) < min)
			min = dp[i / 3] + 1;
		if (i % 2 == 0 && (dp[i / 2] + 1) < min)
			min = dp[i / 2] + 1;
		dp[i] = min;
	}
	cout << dp[x];
	delete[] dp;
	return 0;
}