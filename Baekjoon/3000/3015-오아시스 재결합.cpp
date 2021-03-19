#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, a;
	long long int res = 0;
	stack<pair<int,int>> s;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a;
		pair<int, int> tmp = { a,1 };
		while (!s.empty()) {
			if (s.top().first < a) {
				res += s.top().second;
				s.pop();

			}
			else if (s.top().first == a) {
				tmp.second += s.top().second;
				res += s.top().second;
				s.pop();
			}
			else
				break;
		}
		if (!s.empty())
			res++;
		s.push(tmp);
	}

	cout << res;

	return 0;
}