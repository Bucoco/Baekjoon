#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	vector<int> v;
	int n, m, index;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		v.push_back(i);
	index = m - 1;
	cout << "<";
	while (v.size()>1) {
		cout << v[index]<<", ";
		v.erase(v.begin() + index);
		index = (index + m - 1) % v.size();
	}

	cout<<v[index]<<">";
	return 0;
}