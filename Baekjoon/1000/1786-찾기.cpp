#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cnt = 0;
int F[1000010];
vector<int> ans;

void fail(const string &P) {
	
	for (int i = 1, j = 0; i < P.length(); ++i) {
		while (j > 0 && P[i] != P[j])
			j = F[j - 1];

		if (P[i] == P[j])
			F[i] = ++j;
	}
}

void KMP(const string& T, const string& P) {
	fail(P);
	for (int i = 0, j = 0; i < T.length(); i++) {
		while (j > 0 && T[i] != P[j])
			j = F[j - 1];

		if (T[i] == P[j]) {
			if (j == (P.length() - 1)) {
				cnt++;
				ans.push_back(i - P.length() + 1);
				j = F[j];
			}
			else
				j++;
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string a, b;
	getline(cin, a);
	getline(cin, b);
	
	KMP(a, b);

	cout << cnt << '\n';
	for (int i : ans) {
		cout << i + 1 << ' ';
	}

	return 0;
}