#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int map[505][505]{};
	int n, m, b, ans = 1e9, h = 0;
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];

	for (int k = 0; k <= 256; k++) {
		int temp = b, cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] > k) {
					cnt += 2*(map[i][j] - k);
					temp += map[i][j] - k;
				}
				else if (map[i][j] < k) {
					cnt += k - map[i][j];
					temp -= k - map[i][j];
				}
			}
		}
		if (temp >= 0) {
			if (ans >= cnt) {
				ans = cnt;
				h = k;
			}
		}
	}

	cout << ans << ' ' << h;

	return 0;
}