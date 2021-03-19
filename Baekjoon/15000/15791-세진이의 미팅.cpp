#include <iostream>

using namespace std;

#define MOD 1000000007

long long int cal(long long int a, long long int b) {
	if (!b)
		return 1;
	if (b & 1)
		return (a * cal(a, b - 1) % MOD) % MOD;
	return cal((a*a) % MOD, b / 2) % MOD;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	long long int a = 1, b = 1, c;
	for (int i = 1;i <= n;i++) {
		a *= i;
		a %= MOD;
	}
	for (int i = 1;i <= m;i++) {
		b *= i;
		b %= MOD;
	}
	for (int i = 1;i <= n - m;i++) {
		b *= i;
		b %= MOD;
	}
	c = cal(b, MOD - 2);
	a *= c;
	a %= MOD;

	cout << a;
	return 0;
}