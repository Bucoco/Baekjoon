#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

struct location { int x1, y1, x2, y2; };

int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector<location> v;
	vector<int> v2;

	int xs, ys, xe, ye, x1, y1, x2, y2;
	cin >> xs >> ys >> xe >> ye;

	for (int i = 0;i < 3;i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back({ x1,y1,x2,y2 });
		v.push_back({ x2,y2,x1,y1 });
	}
	v.push_back({ xe,ye,xe,ye });

	for (int i = 0;i < 7;i++) {
		v2.push_back(i);
	}

	int res = INT_MAX;

	do {
		int temp = 0;
		int x = xs, y = ys;
		for (int i = 0;i < 7;i++) {
			temp += dist(x, y, v[v2[i]].x1, v[v2[i]].y1);
			if (v2[i] == 6)
				break;
			temp += 10;
			x = v[v2[i]].x2;
			y = v[v2[i]].y2;
		}
		res = min(res, temp);
	} while (next_permutation(v2.begin(), v2.end()));

	cout << res;

	return 0;
}