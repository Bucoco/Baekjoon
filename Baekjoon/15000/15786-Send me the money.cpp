#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	string str1, str2;
	cin >> str1;
	for (int i = 0;i < m;i++) {
		cin >> str2;
		int index = 0;
		for (int j = 0;j < str2.size() && index<n;j++) {
			if (str2[j] == str1[index])
				index++;
		}
		if (index < n)
			cout << "false\n";
		else
			cout << "true\n";
	}

	return 0;
}