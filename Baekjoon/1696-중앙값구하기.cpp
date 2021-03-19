#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	
	int t, n, a;
	cin >> t;
	while (t--){
		priority_queue<int, vector<int>, greater<int>> minh;
		priority_queue<int, vector<int>, less<int>> maxh;
		cin >> n;
		cout << n / 2 + 1 << "\n";
		for (int i = 0;i < n;i++) {
			cin >> a;
			if (i & 1) 
				minh.push(a);
			else {
				maxh.push(a);
				if (!minh.empty()) {
					int x = maxh.top(), y = minh.top();
					if (x > y) {
						maxh.pop();
						minh.pop();
						maxh.push(y);
						minh.push(x);
					}
				}
				cout << maxh.top() << " ";
			}
			if (i % 20 == 19)
				cout << "\n";
		}
		cout << "\n";
	}

	return 0;
}