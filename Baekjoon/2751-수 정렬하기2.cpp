#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> tmp;

void sort(int start, int end) {
	
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n);
	tmp.resize(n);
	for (auto &i : v)
		cin >> i;
	sort();
	for (auto &i : v)
		cout << i << "\n";

	return 0;
}