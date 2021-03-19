#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int arr[100000] = {};
	int d[100000] = {};
	bool t = false;

	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];

	sort(arr, arr + n);
	for (int i = 0;i < n - 1;i++) {
		d[i] = arr[i + 1] - arr[i];
	}

	sort(d, d + n - 1);
	
	for (int i = 0;i < n;i++)
		if (d[i] % mi != 0) {
			t = true;
			break;
		}


	
	cout << count;
	return 0;
}