#include<iostream>
#include<string>

#define maxSize 10

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
	void Preorder_un(Node*root);	//先序遍历(非递归)
	void Inorder_un(Node *root);	//中序遍历(非递归)
	void Postorder_un(Node *root);	//后序遍历(非递归)
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


//创建二叉树(先序顺序)
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

//先序遍历(非递归)
void BinaryTree::Preorder_un(Node *root) {
	if (root != NULL) {
		Node * Stack[maxSize];//定义栈
		int top = -1;//栈顶
		Node *p;
		Stack[++top] = root;

		while (top != -1) {
			p = Stack[top--];
			cout << p->data<<" ";
			if (p->right != NULL) {//右孩子先入栈（先进后出,左孩子比右孩子先出）
				Stack[++top] = p->right;
			}
			if (p->left != NULL) {//左孩子后入栈
				Stack[++top] = p->left;
			}
		}

	}

}

//中序遍历(非递归)
void BinaryTree::Inorder_un(Node *root) {
	if (root != NULL) {
		Node *Stack[maxSize];
		int top = -1;
		
		Node *p=root;
		
		while (top != -1 || p != NULL) {
			while (p != NULL) {//当前结点作为根结点进行中序遍历 (每个结点可当作局部的树来遍历)
				Stack[++top] = p;
				p = p->left;
			}
			if (top != -1) {
				p = Stack[top--];
				cout << p->data << " ";
				p = p->right;//遍历右孩子
			}
		}
	}
}

//后序遍历(非递归)
void BinaryTree::Postorder_un(Node *root) {
	if (root != NULL) {
		Node *Stack1[maxSize];//逆后序序列栈
		int top1 = -1;
		Node *Stack2[maxSize];//后序列栈
		int top2 = -1;
		
		Node*p = NULL;
		Stack1[++top1] = root;
		
		while (top1 != -1) {//逆后序遍历 （先序遍历左右孩子遍历顺序互换）
			p = Stack1[top1--];
			Stack2[++top2] = p;
			if (p->left != NULL) {//左孩子先入栈
				Stack1[++top1] = p->left;
			}
			if (p->right != NULL) {//右孩子后入栈
				Stack1[++top1] = p->right;
			}
		}
		while (top2 != -1) {//逆后序序列栈出栈，则为后序遍历
			p = Stack2[top2--];
			cout << p->data << " ";
		}
	}
}

//先序遍历
void BinaryTree::Preorder(Node *p) {
	if (p != NULL) {
		cout << p->data << " ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

//中序遍历
void BinaryTree::Inorder(Node *p) {
	if (p != NULL) {
		Inorder(p->left);
		cout << p->data << " ";
		Inorder(p->right);
	}
}

//后序遍历
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
	a.Preorder_un(a.Root());
	cout << endl << "中序遍历" << endl;
	a.Inorder_un(a.Root());
	cout << endl << "后序遍历" << endl;
	a.Postorder_un(a.Root());
	return 0;

}
