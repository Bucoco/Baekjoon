#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	string str;
	int arr[26] = {};
	for (auto &i : arr)
		i = -1;

	cin >> str;
	for (int i = 0;i < str.size();i++) {
		if (arr[str[i] - 'a'] == -1)
			arr[str[i] - 'a'] = i;
	}

	for (auto i : arr)
		cout << i << " ";

	return 0;
}