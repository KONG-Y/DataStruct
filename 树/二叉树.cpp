#include<iostream>
#include<string>
using namespace std;

typedef struct Node {
	char data;
	Node *left; 
	Node *right;
}Node;

class BinaryTree{
public:
	BinaryTree();
	~BinaryTree();
	Node* Create(Node *p);		//构建二叉树（先序顺序）
	void Preorder(Node *root);	//先序遍历
	void Inorder(Node *root);	//中序遍历
	void Postorder(Node *root);	//后序遍历
	int maxDepth(Node *p);		//二叉树的深度/高度
	Node* Root();			//获得根结点
private:
	Node *root;
};

BinaryTree::BinaryTree() {
	root = Create(root);
}

BinaryTree::~BinaryTree() {
}

int BinaryTree::maxDepth(Node*p) {
	if (p == NULL)return 0;
	int left = maxDepth(p->left) + 1;
	int right = maxDepth(p->right) + 1;
	if (left > right) {
		return left; 
	}
	else { 
		return right;
	}
}
Node* BinaryTree::Root() {
	return this->root;
}

Node* BinaryTree::Create(Node *p) {
	char data;
	cin >> data;
	if (data == '#') {//一个#代表一个结点为NULL,叶子结点要两个#
		p = NULL;
	}
	else
	{
		p = new Node;
		p->data = data;
		p->left = Create(p->left);
		p->right = Create(p->right);
	}
	return p;
}


void BinaryTree::Preorder(Node *p) {
	if (p != NULL) {
		cout << p->data << " ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

void BinaryTree::Inorder(Node *p) {
	if (p != NULL) {
		Inorder(p->left);
		cout << p->data << " ";
		Inorder(p->right);
	}
}

void BinaryTree::Postorder(Node *p) {
	if (p != NULL) {
		Postorder(p->left);
		Postorder(p->right);
		cout << p->data << " ";
	}
}

int main() {
	cout << "创建二叉树" << endl;
	BinaryTree a;
	cout << "树的深度: " << a.maxDepth(a.Root());
	cout <<	endl<< "前序遍历" << endl;
	a.Preorder(a.Root());
	cout << endl << "中序遍历" << endl;
	a.Inorder(a.Root());
	cout << endl << "后序遍历" << endl;
	a.Postorder(a.Root());
	return 0;

}
