#include <iostream>
using namespace std;

#define MOD 1000000007

long long cal(long long a, long long b) {
	if (!b)
		return 1;
	if (b & 1)
		return (a * cal(a, b - 1) % MOD) % MOD;
	return cal((a * a) % MOD, b/2) % MOD;
}

long long coef(long long n, long long k) {
	long long a = 1, b = 1;
	for (long long i = 1; i <= n; i++) {
		a *= i;
		a %= MOD;
	}
	for (long long i = 1; i <= k; i++) {
		b *= i;
		b %= MOD;
	}
	for (long long i = 1; i <= n - k; i++) {
		b *= i;
		b %= MOD;
	}

	return (a % MOD * cal(b, MOD - 2) % MOD) % MOD;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	cout << coef(n, k);

	return 0;
}