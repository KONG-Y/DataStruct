#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *next;
}Node;

class Stack
{
public:
	Stack();		//构造
	~Stack();		//析构
	int isEmpty();      	//空栈判断
	void Push(int data);	//入栈
	int Pop();		//出栈
	void Reverse();		//倒置
	void Foreach();		//遍历
private:
	Node *top;		//已栈顶作为链栈的头节点
};

int Stack::isEmpty()
{
	if (top->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Stack::Stack()
{
	top = new Node;
	top->next = NULL;
	top->data = NULL;
}

Stack::~Stack()
{
	while (top->next = NULL)
	{
		Node *p = top->next;
		top->next = p->next;
		delete p;
	}
}

void Stack::Push(int data)
{
	Node *p_new = new Node;
	p_new->data = data;
	if (this->isEmpty())
	{
		p_new->next = NULL;
		top->next = p_new;

	}
	else
	{
		p_new->next = top->next;
		top->next = p_new;
	}
}

int Stack::Pop()
{
	if (this->isEmpty())
	{
		cout << "栈空!" << endl;
	}
	else 
	{
		Node *p = top->next;
		top->next = p->next;
		int x = p->data;
		delete p;
		return x;
	}
}

//倒置链栈
void Stack::Reverse() 
{
	Node * u;		//当前结点
	Node *p = NULL;		//上一结点
	Node *L = top->next;	//下一结点

	while (L!= NULL) 
	{
		u = L;		//当前结点移动到下一结点
		L = L->next;	//下一结点下移
		u->next = p;	//当前结点链接到上一结点
		p = u;		//上一结点移动到下一结点（当前结点位置）
	}
	top->next = p;//栈头链接到栈底
}

void Stack::Foreach()
{
	Node *pCurrent = top->next;
	while (pCurrent != NULL)
	{
		cout << pCurrent->data << " ";
		pCurrent = pCurrent->next;
	}
	cout << endl;
}

int main()
{
	Stack a;

	//入栈
	for (int i = 0; i < 5; i++) {
		a.Push(i);
	}
	a.Foreach();
	a.Reverse();
	a.Foreach();
	return 0;
}
