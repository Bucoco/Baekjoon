#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, ans = 0;
	int arr[103] {};

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum > m)
					continue;
				if (m - sum < m - ans)
					ans = sum;
			}
		}
	}

	cout << ans;

	return 0;
}