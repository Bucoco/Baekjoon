#include <iostream>
#include <algorithm>
using namespace std;

bool arr[10001] = {};
void check(int n) {
	int t = n;
	while (n) {
		t += n % 10;
		n /= 10;
	}
	if (t > 10000 || arr[t])
		return;
	arr[t] = true;
	check(t);
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	for (int i = 1;i <= 10000;i++) {
		check(i);
	}

	for (int i = 1;i <= 10000;i++)
		if (!arr[i])
			cout << i << "\n";
	
	return 0;
}