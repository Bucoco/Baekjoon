#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, b, c;
	int a[1000000] = { };
	long long count = 0;

	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	for (int i = 0;i < n;i++) {
		int t = a[i];
		t -= b;
		if (t > 0) {
			count += t / c;
			if (t%c != 0)
				count++;
		}
	}
	count += n;
	cout << count;

	return 0;
}
