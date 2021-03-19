#include <iostream>
#include <vector>
#include <utility>
using namespace std;

struct Line {
	int x, y1, y2, num;
	Line(int a, int b, int c, int d) {
		x = a;
		y1 = b > c ? b : c;
		y2 = b > c ? c : b;
		num = d;
	}
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, m, k, x, y;

	cin >> t;
	while (t--) {
		cin >> m;
		for (int i = 0;i < m;i++) {
			vector<pair<int, int>> pos;
			cin >> k;
			for (int j = 0;j < k;j++) {
				cin >> x >> y;
				pos.push_back
			}
		}
	}



	return 0;
}