#include <iostream>
using namespace std;

int main() {
	int n, plug, sum = 0;
	cin >> n;
	for (int i = 0;i < n-1;i++) {
		cin >> plug;
		sum += plug - 1;
	}
	cin >> plug;
	sum += plug;
	cout << sum;
	return 0;
}