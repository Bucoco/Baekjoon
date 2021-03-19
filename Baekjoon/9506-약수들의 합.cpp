#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int div[50000] = {};

	while (1) {
		cin >> n;
		int index = 0, sum = 0;
		if (n == -1)
			break;
		int i;
		for (i = 1;i*i < n;i++) {
			if (n%i == 0) {
				div[index++] = i;
				div[index++] = n/i;
				sum += i;
				sum += n/i;
			}
		}
		if (i*i == n) {
			div[index++] = i;
			sum += i;
		}
		sort(div, div + index);
		if (sum == 2 * n) {
			cout << n << " = ";
			for (i = 0;i < index - 2;i++)
				cout << div[i] << " + ";
			cout << div[i] << "\n";
		}
		else
			cout << n << " is NOT perfect.\n";
	}
	return 0;
}