#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int count = str.size();
	for (int i = 1;i < str.size();i++) {
		if (str[i] == '-')
			count--;
		if (str[i] == '=') {
			if (str[i - 1] != 'z')
				count--;
			else if (i > 1 && str[i - 2] == 'd')
				count -= 2;
			else
				count--;
		}
		if (str[i] == 'j')
			if (str[i - 1] == 'n' || str[i - 1] == 'l')
				count--;
	}
	cout << count;
	return 0;
}