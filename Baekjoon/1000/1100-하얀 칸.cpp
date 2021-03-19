#include <iostream>
using namespace std;
#include <string>

int main() {
	string row;
	int count = 0;
	for (int i = 0;i < 8;i++) {
		cin >> row;
		for (int j = 0;j < 8;j++) {
			if (i % 2 == 1 && j % 2 == 1 && row[j] == 'F')
				count++;
			else if (i % 2 == 0 && j % 2 == 0 && row[j] == 'F')
				count++;
		}
	}
	cout << count;
	return 0;
}