#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, cnt = 0;
	cin >> n;

	while (n) {
		if (n < 100) {
			cnt++;
		}
		else if (n >= 1000){ }
		else {
			int t = n;
			int arr[3];
			int i = 0;
			while (t) {
				arr[i++] = t % 10;
				t /= 10;
			}
			if (arr[0] - arr[1] == arr[1] - arr[2])
				cnt++;
		}
		n--;
	}
	cout << cnt;
	return 0;
}