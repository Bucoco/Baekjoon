#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, cnt = 1, a = 1;
	cin >> n;
	for (int i = 1;a < n;i++) {
		a += i * 6;
		cnt++;
	}
	cout << cnt;
	return 0;
}