#include <iostream>
#include <stack>

using namespace std;

//二叉树的建立与遍历,使用非递归法完成遍历
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
	void prtTreeF() {
		p = root;
		stack<node*> s;
		while (!s.empty() || p){	
		   while (p){
		       cout << p->data;
		       s.push(p);
		       p = p->left;
			}
			if (!s.empty()){
			    p = s.top();
			    s.pop();
			    p = p->right;
			}
		}
	}

	//后序遍历
	void prtTreeL() {
		p = root;
		q = nullptr;
		stack<node*> s;
		while (p){
		    s.push(p);
		    p = p->left;
		}
		while (!s.empty()){
		    p = s.top();
		    s.pop();
		    if (p->right == NULL || p->right == q){
		       cout << p->data;
		       q = p;
			}
		    else{
				s.push(p);
		        p = p->right;
		        while (p){
					s.push(p);
		            p = p->left;
		        }
		    }
		}
	}

	//中序遍历
	void prtTreeM() {
		p = root;
		stack<node*> s;
		while (!s.empty() || p){
			while (p){
				s.push(p);
				p = p->left;
			}
			if(!s.empty()){
			    p = s.top();
				s.pop();
				cout << p->data;
			    p = p->right;
			}
		}
	}

};

int main() {

	BiTree biTree = BiTree();
	biTree.prtTreeF();
	cout << endl;
	biTree.prtTreeM();
	cout << endl;
	biTree.prtTreeL();

	while (true);

	return 0;
}
