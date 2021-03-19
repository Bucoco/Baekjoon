#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, t, fr1;
int room[55][55] = {}, dif[55][55] = {}, dj[4] = { 1,0,-1,0 }, di[4] = { 0,1,0,-1 };

void dust() {
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (room[i][j] > 1) {
				int tmp = room[i][j] / 5;
					for (int k = 0;k < 4;k++) {
						int mi = i + di[k], mj = j + dj[k];
						if (mi<r && mi > -1 && mj<c && mj > -1 && room[mi][mj] != -1) {
							dif[mi][mj] += tmp;
							dif[i][j] -= tmp;
						}
					}
			}
		}
	}

	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			room[i][j] += dif[i][j];
			dif[i][j] = 0;
		}
	}

}

void filter() {
	int tmp = 0;
	int fr = fr1;
	for (int i = 1;i < c;i++)
		swap(tmp, room[fr][i]);
	for (int i = fr + 1;i < r;i++)
		swap(tmp, room[i][c - 1]);
	for (int i = c - 2;i > 0;i--)
		swap(tmp, room[r - 1][i]);
	for (int i = r - 1;i > fr;i--)
		swap(tmp, room[i][0]);

	tmp = 0;
	fr--;
	for (int i = 1;i < c;i++)
		swap(tmp, room[fr][i]);
	for (int i = fr - 1 ;i > 0;i--)
		swap(tmp, room[i][c - 1]);

	for (int i = c - 1;i > 0;i--)
		swap(tmp, room[0][i]);

	for (int i = 0;i < fr;i++)
		swap(tmp, room[i][0]);

}

int sum() {
	int res = 0;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (room[i][j] > 0)
				res += room[i][j];
		}
	}
	return res;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c >> t;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> room[i][j];
			if (room[i][j] == -1) {
				fr1 = i;
			}
		}
	}

	for (int i = 0;i < t;i++) {
		dust();
		filter();
	}

	cout << sum();

	return 0;
}