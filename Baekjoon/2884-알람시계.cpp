#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int h, m;
	cin >> h >> m;

	if (m < 45)
		h = (h + 23) % 24;

	cout << h << ' ' << (m + 15) % 60;
	
	return 0;
}