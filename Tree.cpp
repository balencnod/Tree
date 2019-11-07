#include <iostream>

using namespace std;

//二叉树的建立与遍历
struct node {
	char data;
	node* left = nullptr;
	node* right = nullptr;
	node* father = nullptr;
};

class BiTree {
private:

	node* p; node* q; node* r;

public:
	
	node* root;

	BiTree() {

		char s[100];
		int i = 0;
		bool label = true;

		cout << "请输入树：" << endl;
		p = new node;
		root = p;
		cin.getline(s, 100);
		p->data = s[i];
		i++;
		
		do {
			if (s[i] == ' ') {
				if (p->left == nullptr && label) {
					label = false;
				}
				else {
					if (s[i + 1] == '\0') {
						p = p->father;
					}
					else {
						do{
							p = p->father;
						} while (p->right != nullptr);
					}
					label = false;
				}
			}
			else if(s[i] == '\0'){
				break;
			}
			else {
				if (label) {
					q = new node;
					p->left = q;
					q->father = p;
					q->data = s[i];
					p = q;
					label = true;
				}
				else {
					q = new node;
					p->right = q;
					q->father = p;
					q->data = s[i];
					p = q;
					label = true;
				}
			}
			i++;
		} while (true);
	}

	node* getRoot() {
		return root;
	}

	//前序遍历
	void prtTreeF(node* t) {
		p = t;
		cout << p->data;
		if (p->left != nullptr) {
			prtTreeF(p->left);
		}
		if(p->right != nullptr){
			prtTreeF(p->right);
		}
		p = p->father;
	}

	//后序遍历
	void prtTreeL(node* t) {
		p = t;
		if (p->left != nullptr) {
			prtTreeL(p->left);
		}
		if(p->right != nullptr){
			prtTreeL(p->right);
		}
		cout << p->data;
		p = p->father;
	}

	//中序遍历
	void prtTreeM(node* t) {
		p = t;
		if (p->left != nullptr) {
			prtTreeM(p->left);
		}
		cout << p->data;
		if(p->right != nullptr){
			prtTreeM(p->right);
		}
		p = p->father;
	}

};

int main() {

	BiTree biTree = BiTree();
	biTree.prtTreeF(biTree.root);
	cout << endl;
	biTree.prtTreeM(biTree.root);
	cout << endl;
	biTree.prtTreeL(biTree.root);

	while (true);

	return 0;
}
