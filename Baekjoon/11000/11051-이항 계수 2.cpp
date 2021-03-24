#include <iostream>
using namespace std;

#define MOD 10007

int coef[1005][1005];

int cal(int n, int k) {

	for (int i = 0; i <= n; i++) {
		coef[i][0] = 1;
		coef[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			coef[i][j] = coef[i - 1][j - 1] % MOD + coef[i - 1][j] % MOD;
			coef[i][j] %= MOD;
		}
	}
	return coef[n][k] % MOD;
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	cout << cal(n, k);

	return 0;
}