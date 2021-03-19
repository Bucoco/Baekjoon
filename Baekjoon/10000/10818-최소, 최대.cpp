#include <iostream>
using namespace std;

int main() {
	int n;
	int max = -1000000;
	int min = 1000000;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int a;
		cin >> a;
		max = a > max ? a : max;
		min = a < min ? a : min;
	}
	cout << min << " " << max;
	return 0;
}