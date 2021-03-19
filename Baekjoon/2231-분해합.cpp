#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int arr[1000010] = {};
	int sum, temp, n;

	cin >> n;
	for (int i = 1;i<n ; i++) {
		sum = i;
		temp = i;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}

		if (sum > n)
			continue;
		if (!arr[sum])
			arr[sum] = i;			
	}
	
	cout << arr[n];

	return 0;
}