#include <iostream>
using namespace std;
#include <string>

int main() {
	string str;
	int count = 0;
	cin >> str;
	for (int i = 0;i < str.size();i++) {
		switch (str[i]) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			count++;
			break;
		}
	}
	cout << count;
	return 0;
}