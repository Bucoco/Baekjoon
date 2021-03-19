#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cmp(const char &a, const char &b) {
	return a > b;
}

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	string str;
	int sum = 0;
	cin >> str;
	sort(str.begin(), str.end(),cmp);
	for (auto i : str)
		sum += i - '0';

	if (str.back() != '0' || sum % 3)
		cout << -1;
	else
		cout << str;
	return 0;
}