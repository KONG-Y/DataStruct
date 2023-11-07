#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#define maxSize 10

using namespace std;
typedef struct Node {
	int val;
	Node *left; 
	Node *right;
}Node;


class BinaryTree {
public:
	BinaryTree();
	~BinaryTree();
	Node* Create(Node* p);			//构建二叉树（先序顺序）
	void Preorder(Node* root);		//先序遍历
	void Inorder(Node* root);		//中序遍历
	void Postorder(Node* root);		//后序遍历
	vector<int> Preorder_un(Node* root);		//先序遍历(迭代法)
	vector<int> Inorder_un(Node* root);		//中序遍历(迭代法)
	vector<int> Postorder_un(Node* root);		//后序遍历(迭代法)
	vector<vector<int>> LevelOrder(Node* root);	//层序遍历（迭代法）
	int maxDepth(Node* p);			//二叉树的深度/高度
	Node* Root();				//获得根结点
private:
	Node* root;
};

BinaryTree::BinaryTree() {
	root = Create(root);
}

BinaryTree::~BinaryTree() {
}


int BinaryTree::maxDepth(Node* p) {
	if (p == nullptr)return 0;
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
Node* BinaryTree::Create(Node* p) {
	int data;
	cin >> data;
	if (data == '#') {//一个#代表一个结点为NULL,叶子结点要两个#
		p = nullptr;
	}
	else
	{
		p = new Node;
		p->val = data;
		p->left = Create(p->left);
		p->right = Create(p->right);
	}
	return p;
}

//先序遍历(迭代法)
vector<int> BinaryTree::Preorder_un(Node* root) {
	vector<int>result;
	if(!root)return result;
	
	stack<Node*>st;
	st.push(root);
	while(!st.empty()){
		Node*node=st.top();
		st.pop();
		result.push_back(node->val);		//中
		if(node->right)st.push(node->right);	//右入栈（栈特性，先入后出）
		if(node->left)st.push(node->left);	//左入栈
	}
	return result;
}

//后序遍历(迭代法)
vector<int> BinaryTree::Postorder_un(Node* root) {
	vector<int>result;
	if(!root)return result;
	stack<Node*>st;
	st.push(root);
	while(!st.empty()){
		Node*node=st.top();
		st.pop();
		result.push_back(node->val);		//中
		if(node->left)st.push(node->left);	//左入栈（栈特性，先入后出）
		if(node->right)st.push(node->right);	//右入栈
	}
	reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
	return result;
}

//中序遍历(迭代法)
vector<int> BinaryTree::Inorder_un(Node* root) {
	vector<int> result;
        stack<Node*> st;
        Node* cur = root;
        while (cur|| !st.empty()) {
            if (cur) { // 指针来访问节点，访问到最底层
                st.push(cur); // 将访问的节点放进栈
                cur = cur->left;                // 左
            } else {
                cur = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(cur->val);     // 中
                cur = cur->right;               // 右
            }
        }
        return result;
}



//先序遍历（递归法）
void BinaryTree::Preorder(Node* p) {
	if (p == nullptr) return;
	cout << p->val << " ";
	Preorder(p->left);
	Preorder(p->right);
}

//中序遍历（递归法）
void BinaryTree::Inorder(Node* p) {
	if (p == nullptr) return;
	Inorder(p->left);
	cout << p->val << " ";
	Inorder(p->right);
}

//后序遍历（递归法）
void BinaryTree::Postorder(Node* p) {
	if (p == nullptr) return;
	Postorder(p->left);
	Postorder(p->right);
	cout << p->val << " ";
}

//层序遍历（迭代法）
vector<vector<int>> BinaryTree::LevelOrder(Node* root) {
	vector<vector<int>>result;
	if (root == nullptr) return result;
	
	queue<Node*>que;
	que.push(root);
	while (!que.empty()) {
		int size = que.size();
		vector<int>vec;
		for (int i = 0; i < size; i++) {
			Node* node = que.front();
			que.pop();
			vec.push_back(node->val);
			if (node->left)que.push(node->left);
			if (node->right)que.push(node->right);
		}
		result.push_back(vec);
	}
	return result;		
}

int main() {
	cout << "创建二叉树" << endl;
	BinaryTree a;
	cout << "树的深度: " << a.maxDepth(a.Root());
	cout << endl << "前序遍历" << endl;
	a.Preorder_un(a.Root());
	cout << endl << "中序遍历" << endl;
	a.Inorder_un(a.Root());
	cout << endl << "后序遍历" << endl;
	a.Postorder_un(a.Root());
	cout << endl << "层序遍历" << endl;
	a.LevelOrder(a.Root());
	return 0;

}
