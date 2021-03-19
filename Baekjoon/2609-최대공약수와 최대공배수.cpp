#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (!(a%b)) {
		return b;
	}
	return gcd(b, a%b);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;
	if (a < b)
		swap(a, b);
	int g = gcd(a, b);
	cout << g << "\n" << a * b / g;
	return 0;
}