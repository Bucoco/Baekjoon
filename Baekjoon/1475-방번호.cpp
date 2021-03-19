#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string str;
	int arr[10] = {};
	cin >> str;
	for (auto i : str) {
		arr[i - '0']++;
	}
	arr[6] = (arr[6] + arr[9] + 1) / 2;
	arr[9] = 0;
	sort(arr, arr + 10);
	cout << arr[9];
	return 0;
}