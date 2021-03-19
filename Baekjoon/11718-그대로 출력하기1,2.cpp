#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	vector<string> s;
	string str;
	while (getline(cin,str))
	{
		s.push_back(str);
	}

	for (auto i : s)
		cout << i << "\n";

	return 0;
}