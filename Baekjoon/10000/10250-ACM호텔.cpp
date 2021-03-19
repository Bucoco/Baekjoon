#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, h, w, n;
	cin >> t;
	while (t--) {
		cin >> h >> w >> n;
		int room = 0;
		n--;
		room += (n % h+1) * 100 + n / h + 1;
		cout << room << "\n";
	}
	return 0;
}