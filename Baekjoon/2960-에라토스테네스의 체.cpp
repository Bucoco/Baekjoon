#include <iostream>
using namespace std;

int main() {
	int n, k;
	int i;
	int count = 0;
	int arr[1001] = {};

	cin >> n >> k;
	while (count != k) {
		for (i = 2;i < 1001;i++)
			if (!arr[i])
				break;

		for (int j = 1;i*j<=n;j++) {
			if (!arr[i*j]) {
				arr[i*j] = 1;
				count++;
			}
			if (count == k) {
				cout << i*j;
				break;
			}
		}
	}
	return 0;
}