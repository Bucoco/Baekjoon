#include <iostream>
using namespace std;
#include <string>

int main() {
	string str;
	cin >> str;
	for (int i = 0, j = str.size()-1;j >= 0;i++, j--) {
		if (str[i] != str[j]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}