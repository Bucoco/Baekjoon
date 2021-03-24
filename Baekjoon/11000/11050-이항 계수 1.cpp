#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 0 || n == 1)
		return 1;
	return factorial(n - 1) * n;
}

int coef(int n, int k) {
	return factorial(n) / factorial(n - k) / factorial(k);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;

	cin >> n >> k;

	cout << coef(n, k);


	return 0;
}