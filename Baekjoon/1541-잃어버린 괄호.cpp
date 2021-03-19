#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int result = 0, num = 0;
	string str;
	bool isMinus = false;
	cin >> str;

	for (int i = 0;i < str.size();i++) {
		if (str[i] == '+' || str[i] == '-') {
			if (!isMinus) {
				result += num;
			}
			else {
				result -= num;
			}
			if (str[i] == '-')
				isMinus = true;
			num = 0;
		}
		else {
			num = num * 10 + (str[i] - '0');
		}
	}
	if (!isMinus) {
		result += num;
	}
	else {
		result -= num;
	}
	cout << result;
	return 0;
}