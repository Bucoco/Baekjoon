#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, m, k, team = 0;
	cin >> n >> m >> k;
	
	int rest = 0;
	if (n / 2 > m) {
		team = m;
		rest = n - team * 2;
	}
	else {
		team = n / 2;
		rest += n % 2 + m - team;
	}
	
	while (k > rest) {
		team--;
		rest += 3;
	}

	cout << team;
	return 0;
}