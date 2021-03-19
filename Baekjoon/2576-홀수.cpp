#include <iostream>
using namespace std;

int main() {
	unsigned int a;
	int sum = 0, min = 0, count = 0;
	for (int i = 0;i < 7;i++) {
		cin >> a;
		if (a % 2 == 1) {
			sum += a;
			if (count == 0 || a < min)
				min = a;
			count++;
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << "\n" << min;
	return 0;
}