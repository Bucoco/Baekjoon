#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coordinate {
	long long int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
};

int ccw(long long int x1, long long int y1, long long int x2, long long int y2, long long int x3, long long int y3)
{
	long long int temp = x1 * y2 + x2 * y3 + x3 * y1;
	temp = temp - y1 * x2 - y2 * x3 - y3 * x1;
	if (temp > 0) 
		return 1;
	else if (temp < 0) 
		return -1;
	else 
		return 0;
}

bool cmp(const Coordinate &a,const Coordinate &b) {
	return b.x2*a.y2 < a.x2*b.y2;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<Coordinate> radio(n);
	for (int i = 0;i < n;i++) {
		cin >> radio[i].x1 >> radio[i].y1 >> radio[i].x2 >> radio[i].y2;
	}
	cin >> m;
	vector<Coordinate> laser(m);
	for (int i = 0;i < m;i++) {
		cin >> laser[i].x2 >> laser[i].y2;
	}
	sort(laser.begin(), laser.end(), cmp);
	int cnt = n;
	for (int i = 0;i < n;i++) {
		int l = 0, r = m - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			int c1 = ccw(0, 0, laser[mid].x2, laser[mid].y2, radio[i].x1, radio[i].y1);
			int c2 = ccw(0, 0, laser[mid].x2, laser[mid].y2, radio[i].x2, radio[i].y2);

			if (c1 > 0 && c2 > 0) {
				l = mid + 1;
			}
			else if (c1 < 0 && c2 < 0) {
				r = mid - 1;
			}
			else {
				cnt--;
				break;
			}
		}
	}

	cout << cnt;
	return 0;
}