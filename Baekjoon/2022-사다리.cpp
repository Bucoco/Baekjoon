#include <iostream>
#include <cmath>
using namespace std;

double x, y, c;
bool sol(double mid) {
	double a = sqrt(x*x - mid * mid), b = sqrt(y*y - mid * mid), tmp;
	tmp = a * b / (a + b);
	if (tmp > c)
		return false;
	else
		return true;
	
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> x >> y >> c;

	double l = 0, r = x < y ? x : y, res;
	while (r-l > 0.000001) {
		double mid = (l + r)/2;
		if (sol(mid)) {
			res = mid;
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << fixed;
	cout.precision(3);
	cout << res;

	return 0;
}