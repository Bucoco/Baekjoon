#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	bool arr[1000010]{};
	int cnt = 0;
	long long Min, Max, n;

	cin >> Min >> Max;
	n = Max - Min + 1;

	for (long long i = 2; i*i <= Max; i++) {
		long long  p = i * i;
		long long temp = Min % p;
		long long start = 1;
		if (temp != 0) 
			start += p - temp;

		while (start <= n) {
			if (!arr[start]) {
				arr[start] = true;
				cnt++;
			}
			start += p;
		}
	}

	cout << n - cnt;

	return 0;
}