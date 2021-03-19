#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, cnt = 0;
	cin >> n;

	for (int i = 666;;i++) {
		string str = to_string(i);
		if (str.find("666") != string::npos) {
			cnt++;
		}
		if (cnt == n) {
			cout << i;
			break;
		}
	}

	return 0;
}