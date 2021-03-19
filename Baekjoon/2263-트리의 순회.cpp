#include <iostream>
#include <vector>

using namespace std;

vector<int> inorder;
vector<int> postorder;
vector<int> position;

void preorder(int start,int end, int r) {
	if (start > end)
		return;
	int root = postorder[r];
	int index = position[root];

	cout << root << " ";
	preorder(start, index - 1,r - 1- end + index);
	preorder(index + 1, end,r - 1);
}


int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	inorder.resize(n);
	postorder.resize(n);
	position.resize(n+1);

	for (int i = 0;i < n;i++) {
		cin >> inorder[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> postorder[i];
	}
	for (int i = 0;i < n;i++) {
		position[inorder[i]] = i;
	}

	preorder(0, n - 1,n - 1);

	return 0;
}