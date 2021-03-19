#include <iostream>
using namespace std;
#include <stdio.h>

int main() {
	int n, f;
	cin >> n >> f;
	int q;
	q = n / 100;
	n = n + f - (n % f);
	while ((n-f) / 100 == q) {
		n -= f;
	}
	n %= 100;
	printf("%02d",n);
	return 0;
}