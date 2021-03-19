#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, x, y;
	long long d, cur, cnt;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		d = y - x;
		cur = 1;
		cnt = 0;
		while (d) {
			if (d >= 2 * cur) {
				d -= 2 * cur;
				cur++;
				cnt += 2;
			}
			
			else {
				if (d <= cur) {
					cnt++;
				}
				else {
					cnt += 2;
				}
				break;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}