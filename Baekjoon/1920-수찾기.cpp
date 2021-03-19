#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m, num;
	vector<int> v;
	cin >> n;
	v.resize(n);
	
	for (int i = 0;i < n;i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cin >> m;
	int f, e, mid;
	while (m--) {
		cin >> num;
		f = 0;
		e = n - 1;
		bool check = false;
		while (f<=e) {
			mid = (f + e) / 2;
			if (v[mid] > num)
				e = mid - 1;
			else if (v[mid] < num)
				f = mid + 1;
			else {
				check = true;
				break;
			}
		}
		cout << check << "\n";
	}

	return 0;
}


/*int h(int num) {
	num %= 65539;
	if (num < 0)
		return num * -1;
	else
		return num;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	vector<int> v[65539];
	int n, m, num;
	cin >> n;
	while (n--) {
		cin >> num;
		v[h(num)].push_back(num);
	}
	cin >> m;
	while (m--) {
		bool check = false;
		cin >> num;
		for (auto i : v[h(num)]) {
			if (i == num) {
				check = true;
				break;
			}
		}
		cout << check << "\n";
	}
	
	return 0;
}*/
