#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, x, y, d, g;
	bool visit[105][105] = {};
	int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
	vector<int> curve;
	curve.push_back(0);
	
	for (int i = 0;i < 10;i++) {
		for (int j = curve.size()-1;j >= 0;j--) {
			curve.push_back((curve[j] + 1) % 4);
		}
	}

	cin >> n;
	while (n--) {
		cin >> x >> y >> d >> g;
		int temp = pow(2, g);
		int mx = x, my = y;

		visit[y][x] = true;
		for (int i = 0;i < temp;i++) {
			mx = mx + dx[(curve[i]+d)%4], my = my + dy[(curve[i]+d)%4];
			visit[my][mx] = true;
		}
	}

	int cnt = 0;
	for (int i = 0;i < 100;i++) {
		for (int j = 0;j < 100;j++) {
			if (visit[i][j] && visit[i][j + 1] && visit[i + 1][j] && visit[i + 1][j + 1])
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}