#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}


int main() {
	int dwarf[9] = {};
	int sum = 0;
	for (int i = 0;i < 9;i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}

	for (int i = 0;i < 9;i++) {
		for (int j = i + 1;j < 9;j++) {
			if (sum - dwarf[i] - dwarf[j] == 100) {
				dwarf[i] = dwarf[j] = 101;
				break;
			}
		}
		if (dwarf[i] == 101)
			break;
	}
	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 8-i;j++) {
			if (dwarf[j] > dwarf[j + 1])
				swap(dwarf[j], dwarf[j + 1]);
		}
	}

	for (int i = 0;i < 7;i++)
		cout << dwarf[i] << "\n";
	return 0;
}