#include<iostream>
#include<string>
using namespace std;
class wheel {
public:
	char c[8];
public:
	void setC(char arr[8]) {
		for (int i = 0; i < 8; i++) {
			c[i] = arr[i];
		}
	}
	char getLeft() {
		return this->c[6];
	}
	char getRight() {
		return this->c[2];
	}
	void spin() {
		char tmp = c[7];
		for (int i = 7; i > 0; i--) {
			c[i] = c[i - 1];
		}
		c[0] = tmp;
	}
	void rspin() {
		char tmp = c[0];
		for (int i = 0; i < 7; i++)
			c[i] = c[i + 1];
		c[7] = tmp;
	}
};

wheel w[4];
int k, ans;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	for (int i = 0; i < 4; i++) {
		char s[8];
		for (int j = 0; j < 8; j++) {
			cin >> s[j];
		}
		w[i].setC(s);
	}
	cin >> k;
	while (k--) {
		int num, dir;
		cin >> num >> dir;
		num--;
		bool flagL = false, flagR = false;
		
		if (num == 0) {
			char b = w[1].getLeft();
			char a = w[0].getRight();

			if (a!=b) {
				flagR = true;
			}
			
		}
		else if (num == 3) {
			if (w[num].getLeft() != w[num - 1].getRight())
				flagL = true;
		}
		else {
			if (w[num].getRight() != w[num + 1].getLeft())
				flagR = true;
			if (w[num].getLeft() != w[num - 1].getRight())
				flagL = true;
		}
		if (dir == 1) {
			w[num].spin();
		}
		else {
			w[num].rspin();
		}
		if (flagL) {
			if (dir == 1) {
				w[num - 1].rspin();
			}
			else {
				w[num - 1].spin();
			}
		}
		if (flagR) {
			if (dir == 1) {
				w[num + 1].spin();
			}
			else {
				w[num + 1].rspin();
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (w[i].c[0] == '1')
			ans += (1 << i);
	}
	cout << ans << '\n';
	return 0;
}