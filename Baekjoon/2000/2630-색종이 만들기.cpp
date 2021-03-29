#include <iostream>
using namespace std;

int arr[150][150];
int ans[2]{};

void cal(int x, int y, int size) {
	int temp = arr[y][x];

	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (arr[i][j] != temp) {
				cal(x, y, size / 2);
				cal(x, y + size / 2, size / 2);
				cal(x + size / 2, y, size / 2);
				cal(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}

	ans[temp]++;
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	cal(0, 0, n);

	cout << ans[0] << '\n' << ans[1];

	return 0;
}