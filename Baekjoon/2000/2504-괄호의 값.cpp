#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string str;
	int res = 0, mul = 1;
	stack<int> st;

	cin >> str;

	for (int i = 0;i < str.size();i++) {
		if (str[i] == ')') {
			if (st.empty() || st.top() != '(') {
				res = 0;
				break;
			}
			if (str[i - 1] == '(')
				res += mul;
			mul /= 2;
			st.pop();
		}
		else if (str[i] == ']') {
			if (st.empty() || st.top() != '[') {
				res = 0;
				break;
			}
			if (str[i - 1] == '[')
				res += mul;
			mul /= 3;
			st.pop();
		}
		else {
			if (str[i] == '(')
				mul *= 2;
			else if (str[i] == '[')
				mul *= 3;
			st.push(str[i]);
		}
	}
	if (!st.empty()) res = 0;
	cout << res;

	return 0;
}