#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = -(n-1);i < n;i++) {
		int tmp = i;
		if (tmp < 0)
			tmp *= -1;
		for (int j = 0;j < n - tmp;j++)
			cout << "*";
		cout << "\n";
	}
	return 0;
}