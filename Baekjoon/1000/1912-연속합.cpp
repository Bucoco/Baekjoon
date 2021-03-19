#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, max;
	int dp[100010] = {};
	cin >> n;
	vector<int> v(n);
	for (auto &i : v)
		cin >> i;

	dp[0] = v[0];
	max = dp[0];
	for (int i = 1;i < n;i++) {
		if (dp[i - 1] < 0) {
			dp[i] = v[i];
		}
		else {
			dp[i] = dp[i - 1] + v[i];
		}
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;

	return 0;
}