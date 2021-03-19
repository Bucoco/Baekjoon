#include <iostream>
using namespace std;

int main() {
	int n, x, y, w, h;
	int arr[101][101] = {};
	int count[100] = { 0 };
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> x >> y >> w >> h;
		for (int j = y;j < y+h;j++) {
			for (int k = x;k < x+w;k++)
				arr[j][k] = i + 1;
		}
	}

	for (int i = 0;i < 101;i++) {
		for (int j = 0;j < 101;j++) {
			if (arr[i][j] != 0)
				count[arr[i][j] - 1]++;
		}
	}

	for (int i = 0;i < n;i++)
		cout << count[i] << "\n";
		
	return 0;
}