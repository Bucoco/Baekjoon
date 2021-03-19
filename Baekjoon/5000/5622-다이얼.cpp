#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string str;
	int arr[26] = {};
	int a = 0;
	cin >> str;
	for (int i = 3;i < 11;i++) {
		arr[a++] = i;
		arr[a++] = i;
		arr[a++] = i;
		if (i == 8 || i == 10)
			arr[a++] = i;
	}


	int t = 0;
	for (auto i : str) {
		t += arr[i - 'A'];
	}

	cout << t;
	return 0;
}