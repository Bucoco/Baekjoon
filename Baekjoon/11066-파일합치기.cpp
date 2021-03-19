#include <iostream>
#include <string.h>
using namespace std;

long long int dp[505][505] = {};
int arr[505] = {};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, k;
	cin >> t;
	while (t--) {
		cin >> k;
		memset(dp, 0, sizeof(dp));
		for (int i = 0;i < k;i++)
			cin >> arr[i];

		for (int i = 0;i < k;i++) {
			for (int j = 1;j <= i;j++) {
				dp[0][i] = dp[0][j - 1] + dp[j][i];
			}
			                                                                                                                                
		}




	}




	return 0;
}