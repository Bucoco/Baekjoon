#include <iostream>
#include <string>
using namespace std;

char arr[3073][6145];

void star(int x, int y, int n) {
	if (n == 3) {
		arr[y][x - 2] = arr[y][x - 1] = arr[y][x + 1] = arr[y][x + 2] = arr[y][x + 3] =
			arr[y + 1][x - 2] = arr[y + 1][x] = arr[y + 1][x + 2] = arr[y + 1][x + 3] =
			arr[y + 2][x + 3] = ' ';
		arr[y][x] =
			arr[y + 1][x - 1] = arr[y + 1][x + 1] =
			arr[y + 2][x - 2] = arr[y + 2][x - 1] = arr[y + 2][x] = arr[y + 2][x + 1] = arr[y + 2][x + 2] = '*';
	}
	else {
		for (int i = y;i < y + n / 2;i++) {
			for (int j = x - n+1;j <= x - n / 2;j++) {
				arr[i][j] = ' ';
			}
		}
		star(x, y, n/2);
		for (int i = y ;i < y + n;i++) {
			for (int j = x +n/2+ 1;j <= x + n ;j++) {
				arr[i][j] = ' ';
			}
		}
		star(x - n / 2, y + n / 2, n / 2);
		star(x + n / 2, y + n / 2, n / 2);
	}
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	star(n-1, 0, n);

	for (int i = 0;i < n;i++) {
		for(int j=0;j<n*2;j++)
			cout << arr[i][j];
		cout << "\n";
	}
	return 0;
}