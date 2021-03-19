#include <iostream>

using namespace std;

void hanoi(int bot, int s, int d) {
	if(bot!=1)
		hanoi(bot - 1, s, 6 - s - d);
	cout << s << " " << d << "\n";
	if(bot!=1)
		hanoi(bot - 1, 6 - s - d, d);
}

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	cout << ( 1 << n )-1 << "\n";
	hanoi(n, 1, 3);

	return 0;
}