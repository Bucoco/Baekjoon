#include <iostream>
using namespace std;

int main() {
	int n;
	int arr[50] = {};
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	if (n == 1)
		cout << "A";

	else if (n == 2) {
		if (arr[0] == arr[1])
			cout << arr[0];
		else
			cout << "A";
	}

	else {
		int a;
		if (arr[1] == arr[0])
			a = 0;
		else
			a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
		int b;
		b = arr[1] - a * arr[0];

		for (int i = 0;i < n-1;i++) {
			if (arr[i + 1] != a * arr[i] + b) {
				cout << "B";
				return 0;
			}
		}
		cout << a * arr[n - 1] + b;
	}
	return 0;
	
}