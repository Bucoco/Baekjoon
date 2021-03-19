#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n = 100000;
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h));

	cout << h << " " << tree_size;
}