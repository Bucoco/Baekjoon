#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string str;
	int cnt = 0;

	while (cin >> str || !cnt) {
		cnt++;
	}
	
	if (str == "")
		cnt--;

	cout << cnt;
	return 0;
}