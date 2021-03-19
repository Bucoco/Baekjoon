#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, k, n;
	int arr[15][14] = {};
	for (int i = 0;i < 14;i++) {
		arr[0][i] = i + 1;
	}

	for (int i = 1;i < 15;i++) {
		arr[i][0] = 1;
		for (int j = 1;j < 14;j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	cin >> t;
	while (t--) {
		cin >> k >> n;
		cout << arr[k][n - 1] << "\n";
	}
	return 0;
}