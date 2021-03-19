#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;
	string* strPtr;
	cin >> str;
	strPtr = new string[str.size()];
	strPtr[0] = str;
	for (int i = 1;i < str.size();i++)
		strPtr[i] = strPtr[i-1].substr(1);

	sort(strPtr, strPtr + str.size());
	for (int i = 0;i < str.size();i++) {
		cout << strPtr[i] << "\n";
	}

	delete[] strPtr;
	return 0;
}