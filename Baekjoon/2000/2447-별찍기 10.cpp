#include <iostream>
#include <string.h>
using namespace std;

char arr[2188][2188];

void star(int a, int b, int num) {
	if (num == 1)
		return;
	for (int i = 0;i < num / 3;i++) {
		for (int j = 0;j < num / 3;j++)
			arr[a + num / 3 + i][b + num / 3 + j] = ' ';
	}

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			if (i*j == 1)
				continue;
			star(a + (num / 3 * i), b + (num / 3 * j), num / 3);
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	for (int i = 0;i < n;i++)
		memset(arr[i], '*', n);

	star(0, 0, n);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			cout << arr[i][j];
		cout << "\n";
	}


	return 0;
}