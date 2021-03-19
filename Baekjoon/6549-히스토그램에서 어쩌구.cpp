#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	long long int n, h;
	while (true) {
		long long int res = 0, width;
		vector<long long int> v;
		stack<int> st;
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0;i < n;i++) {
			cin >> h;
			v.push_back(h);
		}
	
		for (int i = 0;i < n;i++) {
			while (!st.empty() && v[st.top()] > v[i]) {
				int tmp = st.top();
				st.pop();
				if (st.empty())
					width = i;
				else
					width = i - st.top() - 1;
				res = res > (width*v[tmp]) ? res : (width*v[tmp]);
			}
			
			st.push(i);
		}

		while (!st.empty()) {
			int tmp = st.top();
			st.pop();
			if (st.empty())
				width = n;
			else
				width = n - st.top() - 1;
			res = res > (width*v[tmp]) ? res : (width*v[tmp]);
		}
		cout << res << '\n';
	}

	return 0;
}