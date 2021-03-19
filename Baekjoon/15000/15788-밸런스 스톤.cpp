#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int n;

long long int row(int y) {
	long long int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += v[y][i];
	}
	return sum;
}

long long int col(int x) {
	long long int sum = 0;
	for (int i = 0;i < n;i++) {
		sum += v[i][x];
	}
	return sum;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int x, y;
	cin >> n;
	v.resize(n);
	for (int i = 0;i < n;i++) {
		v[i].resize(n);
		for (int j = 0;j < n;j++) {
			cin >> v[i][j];
			if (!v[i][j]) {
				y = i;
				x = j;
			}
		}
	}

	long long int sum = 0, r = 0, d1 = 0, d2 = 0, dif;

	sum = row(y);
	if(!y){
		r = row(1);
	}
	else {
		r = row(0);
	}
	dif = r - sum;
	for (int i = 0;i < n;i++) {
		if (i != x) {
			if (col(i) != sum + dif) {
				dif = -1;
				break;
			}
		}
		if (i != y) {
			if (row(i) != sum + dif) {
				dif = -1;
				break;
			}
		}
	}

	if (dif != -1) {
		for (int i = 0;i < n;i++) {
			d1 += v[i][i];
			d2 += v[i][n - i - 1];
		}
		if (x == y && x + y == n - 1) {
			if (d1 != d2)
				dif = -1;
		}
		else if (x == y) {
			if (d1 + dif != d2)
				dif = -1;
		}
		else if (x + y == n - 1) {
			if (d2 + dif != d1)
				dif = -1;
		}
	}

	if (dif < 1)
		cout << -1;
	else
		cout << dif;

	return 0;
}