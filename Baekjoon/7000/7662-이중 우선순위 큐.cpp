#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	multiset<int> pq;

	int t, k, n;
	char op;

	cin >> t;
	while (t--) {
		cin >> k;
		while (k--) {
			cin >> op >> n;
			if (op == 'I') {
				pq.insert(n);
			}
			else {
				if (!pq.empty()) {
					if (n == -1) {
						pq.erase(pq.begin());
					}
					else {
						auto it = pq.end();
						it--;
						pq.erase(it);
					}
				}
			}
		}
		if (pq.empty())
			cout << "EMPTY\n";
		else {
			auto it = pq.end();
			cout << *(--it) << ' ';
			it = pq.begin();
			cout << *it << '\n';
		}
		pq.clear();
	}

	return 0;
}