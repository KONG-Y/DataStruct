#include<iostream>
#include<string>
using namespace std;

typedef struct Node {
	char data;
	int ltag;
	int rtag;
	Node *left;
	Node *right;
}Node;

class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	Node* Create(Node *p);				//构建二叉树（先序顺序）
	void Preorder(Node *root);			//先序遍历
	void Inorder(Node *root);			//中序遍历
	void Postorder(Node *root);			//后序遍历
	void PreThread(Node *p, Node*&pre);	//先序线索化
	void InThread(Node *p, Node*&pre);	//中序线索化
	void PostThread(Node *p, Node*&pre);//后序线索化
	void createInThread(Node *root);	//创建中序线索二叉树
	Node *First(Node *p);
	Node *Next(Node *p);
	
	int maxDepth(Node *p);		//二叉树的深度/高度
	Node* Root();				//获得根结点
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
Node* BinaryTree::First(Node *p) {
	while (p->ltag == 0) {//左孩子
		p = p->left;
	}
	return p;
}
Node* BinaryTree::Next(Node *p) {
	if (p->rtag == 0) {//右孩子
		return First(p->right);
	}
	else {//后继
		return p->right;
	}
}

void BinaryTree::PreThread(Node *p, Node*&pre) {
	if (p != NULL) {
		if (p->left == NULL) {//当前左孩子结点为空指针域，配置前驱
			p->left = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->right == NULL) {//前驱右孩子结点为空指针域，配置后继
			pre->right = p;
			pre->rtag = 1;
		}
		pre = p;//当前结点作为下一结点的前驱

		if (p->ltag == 0) {//左子树线索化
			PreThread(p->left, pre);
		}
		if (p->rtag == 0) {//右子树线索化
			PreThread(p->right, pre);
		}
	}
}

void BinaryTree::InThread(Node*p, Node*&pre) {
	if (p != NULL) {
		InThread(p->left, pre);//左子树线索化

		if (p->left == NULL) {//当前左孩子结点为空指针域, 建立当前结点的前驱线索
			p->left = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->right == NULL) {//前驱右孩子结点为空指针域，建立前驱结点的后继线索
			pre->right = p;
			pre->rtag = 1;
		}

		pre = p;				//当前结点作为下一结点的前驱
		InThread(p->right, pre);//右子树线索化

	}
}

void BinaryTree::PostThread(Node*p, Node*&pre) {
	if (p != NULL) {
		PostThread(p->left, pre);//左子树线索化
		PostThread(p->right, pre);//右子树线索化
		
		if (p->left == NULL) {//当前结点左孩子结点为空指针域，配置前驱
			p->left = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->right == NULL) {//前驱右孩子结点为空指针域，配置后继
			pre->right = p;
			pre->rtag = 1;
		}
		pre = p;//当前结点作为下一结点前驱
	}
}

void BinaryTree::createInThread(Node *root) {
	Node *pre = NULL;
	if (root != NULL) {
		InThread(root, pre);
		pre->right = NULL;
		pre->rtag = 1;
	}
}


void BinaryTree::Inorder(Node *root) {
	for (Node *p = First(root); p != NULL; p = Next(p)) {
		cout << p->data << " ";
	}
}

void BinaryTree::Preorder(Node *root) {
	if (root != NULL) {
		Node *p = root;
		while (p != NULL) {
			while (p->ltag == 0) {//遍历前驱
				cout << p->data << " ";
				p = p->left;
			}
			cout << p->data << " ";
			p = p->right;//后继作为当前结点
		}
	}
}

int main() {
	cout << "创建二叉树" << endl;
	BinaryTree a;
	cout << "树的深度: " << a.maxDepth(a.Root());
	cout << endl << "前序遍历" << endl;
	a.Preorder(a.Root());
	cout << endl << "中序遍历" << endl;
	a.Inorder(a.Root());
	cout << endl << "后序遍历" << endl;
	a.Postorder(a.Root());
	return 0;

}
