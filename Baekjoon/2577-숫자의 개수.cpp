#include <iostream>

using namespace std;

int main() {
	int a, b, c, mul;
	int arr[10] = { 0 };

	cin >> a >> b >> c;

	mul = a * b * c;
	while (mul > 0) {
		switch (mul % 10) {
		case 0:
			arr[0]++;
			break;
		case 1:
			arr[1]++;
			break;
		case 2:
			arr[2]++;
			break;
		case 3:
			arr[3]++;
			break;
		case 4:
			arr[4]++;
			break;
		case 5:
			arr[5]++;
			break;
		case 6:
			arr[6]++;
			break;
		case 7:
			arr[7]++;
			break;
		case 8:
			arr[8]++;
			break;
		case 9:
			arr[9]++;
			break;
		}
		mul /= 10;
	}
	
	for (int i = 0;i < 10;i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}