#include <iostream>
using namespace std;
#include <string>

int main() {
	int h, w;
	string joi;
	int cloud[100][100] = { 0 };
	int count = -1;

	cin >> h >> w;
	for (int i = 0;i < h;i++) {
		cin >> joi;
		for (int j = 0;j < w;j++) {
			if (joi[j] == 'c') {
				count = 0;
				continue;
			}
			else if (count != -1) {
				count++;
				cloud[i][j] = count;
				continue;
			}
			cloud[i][j] = count;
		}
		count = -1;
	}

	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++)
			cout << cloud[i][j] << " ";
		cout << "\n";
	}
	return 0;
}