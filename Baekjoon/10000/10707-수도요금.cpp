#include <iostream>
using namespace std;
#include <algorithm>

int main() {
	int a, b, c, d, p;
	int x, y;
	cin >> a >> b >> c >> d >> p;

	x = a * p;
	if (p > c)
		y = b + (p - c)*d;
	else
		y = b;
	cout << min(x, y);
	return 0;
}