#include <iostream>
#include <set>
#include <string>
using namespace std;

template<typename T>
class treeNode {
public:
	treeNode(T d) {
		data = d;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	T data;
	treeNode* left;
	treeNode* right;
	treeNode* parent;
};

template<typename T>
class BST {
public:
	BST() {
		treesize = 0;
		cnt = 0;
		root = NULL;
	}
	bool Empty() {
		return treesize == 0;
	}
	int Size() {
		return treesize;
	}
	treeNode<T>* Search(T key, treeNode<T>* node) {
		if (node != NULL) {
			if (key < node->data) {
				return Search(key, node->left);
			}
			else if (key > node->data) {
				return Search(key, node->right);
			}
			else
				return node;
		}
		return node;
	}

	void Insert(T key, treeNode<T>* node) {
		if (Empty()) {
			root = new treeNode<T>(key);
			treesize++;
			return;
		}
		if (node != NULL) {
			if (key < node->data) {
				if (node->left == NULL) {
					treeNode<T>* newNode = new treeNode<T>(key);
					node->left = newNode;
					newNode->parent = node;
					treesize++;
				}
				else
					Insert(key, node->left);
			}
			else {
				if (node->right == NULL) {
					treeNode<T>* newNode = new treeNode<T>(key);
					node->right = newNode;
					newNode->parent = node;
					treesize++;
				}
				else
					Insert(key, node->right);
			}
		}
	}

	void Insert(T key) {
		treeNode<T>* newNode = new treeNode<T>(key);
		treeNode<T>* cur = root;
		treeNode<T>* par = NULL;

		if (Empty()) {
			root = newNode;
			treesize++;

			return;
		}

		while (cur != NULL) {
			par = cur;
			if (key < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		newNode->parent = par;
		if (key < par->data)
			par->left = newNode;
		else
			par->right = newNode;
		treesize++;

	}


	void Delete(T key) {
		if (!Empty()) {
			treeNode<T>* node = Search(key, root);
			if (node != NULL) {
				if (node->left == NULL) {
					if (node->parent == NULL) {
						root = root->right;
					}
					else {
						if (node->data < node->parent->data) {
							node->parent->left = node->right;
						}
						else {
							node->parent->right = node->right;
						}
					}
					delete node;
				}
				else if (node->right == NULL) {
					if (node->parent == NULL) {
						root = root->left;
					}
					else {
						if (node->data < node->parent->data) {
							node->parent->left = node->left;
						}
						else {
							node->parent->right = node->left;
						}
					}
					delete node;
				}
				else {
					treeNode<T>* successor = node->right;
					while (successor->left != NULL) {
						successor = successor->left;
						cnt++;
					}
					node->data = successor->data;
					successor->parent->left = successor->right;
					delete successor;
				}
				treesize--;
			}
		}
	}

	void postorder(treeNode<T>* node) {
		if (node != NULL) {
			postorder(node->left);
			postorder(node->right);
			cout << node->data << "\n";
		}
	}

	string preorder(treeNode<T>* node) {
		string res;
		if (node->left != NULL) {
			res += 'L';
			res += preorder(node->left);
			res += 'r';
		}
		if (node->right != NULL) {
			res += 'R';
			res += preorder(node->right);
			res += 'r';
		}
		return res;
	}

	void destructor(treeNode<T>* node) {
		if (node != NULL) {
			destructor(node->left);
			destructor(node->right);
			delete node;
		}
	}
	treeNode<T>* getRoot() {
		return root;
	}

	int getCnt() {
		return cnt;
	}

	~BST() {
		destructor(root);
	}

private:
	int treesize;
	int cnt;
	treeNode<T>* root;
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k;
	set<string> res;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		int a;
		BST<int> tree;
		for (int j = 0;j < k ;j++) {
			cin >> a;
			tree.Insert(a);
		}
		res.insert(tree.preorder(tree.getRoot()));
	}

	cout << res.size();
	return 0;
}