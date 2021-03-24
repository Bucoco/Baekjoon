#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int l;
	const long long M = 1234567891;
	long long r = 1;
	long long ans = 0;
	string str;
	cin >> l >> str;

	for (int i = 0; i < l; i++) {
		ans += (str[i] - 'a' + 1) * r % M;
		ans %= M;
		r *= 31;
		r %= M;
	}

	cout << ans;

	return 0;
}