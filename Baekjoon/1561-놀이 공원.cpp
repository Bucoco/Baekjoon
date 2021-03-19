#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	long long int n, m;
	int arr[10010] = {};
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		cin >> arr[i];
	}

	long long int l = 0, r = 60000000000, res;
	while (l <= r) {
		long long int mid = (l + r) / 2;
		long long int total = m;
		for (int i = 1;i <= m;i++) {
			total += mid / arr[i];
		}
		if (n <= total) {
			res = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	if (n <= m)
		cout << n;
	else {
		long long int total = m;
		for (int i = 1;i <= m;i++) {
			total += (res - 1) / arr[i];
		}
		for (int i = 1;i <= m;i++) {
			if (res%arr[i] == 0)
				total++;
			if (total == n) {
				cout << i;
				break;
			}
		}
	}

	return 0;
}