#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, x, t, a, b;
	int matrix[1010][1010] = {};
	cin >> n >> m >> x;

	for (int i = 0;i < 1010;i++) {
		for (int j = 0;j < 1010;j++)
			matrix[i][j] = 1010000;
	}

	for (int i = 0;i < m;i++) {
		cin >> a >> b >> t;
		matrix[a][b] = t;
	}

	matrix[x][x] = 0;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			for (int k = 1;k <= n;k++) {
				matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
			}
		}
	}

	int result = 0;
	for (int i = 1;i <= n;i++) {
		result = max(result, matrix[i][x] + matrix[x][i]);
	}

	cout << result;

	return 0;
}