#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	int coin[100] = {};
	int dp[10001] = {};
	cin >> n >> k;
	for (int i = 0;i < n;i++)
		cin >> coin[i];
	dp[0] = 1;
	for (int i = 0;i < n;i++) {
		for (int j = coin[i];j <= k;j++)
			dp[j] += dp[j - coin[i]];
	}
	cout << dp[k];
	return 0;
}