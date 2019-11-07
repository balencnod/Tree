#include <iostream>

using namespace std;

//打印二叉树结构
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
		if (s[0] == '\0') {
			root = nullptr;
		}
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

	int getDepth(node* t) {
		int result = 0;
		if (t == root) {
			return 0;
		}
		else {
			do {
				result++;
				t = t->father;
			}while (t != root);
		return result;
		}
	}

	//遍历图
	void prtTreeM(node* t) {
		if (t == nullptr) {
			cout << "空树！" << endl;
			return;
		}
		p = t;
		if (p->left != nullptr) {
			prtTreeM(p->left);
		}
		int depth = getDepth(t);
		for (; depth > 0; depth--) {
			cout << "	";
		}
		cout << p->data << endl;
		if(p->right != nullptr){
			prtTreeM(p->right);
		}
		p = p->father;
	}

};

int main() {

	BiTree biTree = BiTree();
	biTree.prtTreeM(biTree.root);

	while (true);

	return 0;
}
