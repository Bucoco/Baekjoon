#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	if (a > b)
		cout << '>';
	else if (a < b)
		cout << '<';
	else
		cout << "==";

	return 0;
}