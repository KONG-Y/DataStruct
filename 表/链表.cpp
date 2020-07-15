#include<iostream>
using namespace std;

typedef struct Node{
	int data;
	Node *next;
}Node;

class Link {
public:	
	Link();
	~Link();
	void Insert(int index,int value);//插入
	void Delete(int index);			  //删除
	int Length();					        //长度
	bool isEmpty();					      //是否空
	void Foreach();					      //遍历
	Node *Search_node(int index);	//按索引查找结点
	int Search_value(int value);	//按数值查找结点索引
private:
	Node *head;
	int count;
};

Link::Link() {
	this->head = new Node;
	head->next = NULL;
	this->count = 0;
}

Link::~Link() {
	Node *p = this->head->next;
	Node *h;
	while (p != NULL) {
		h = p;
		p = p->next;
		delete h;
	}
}

bool Link::isEmpty() {
	if (this->head->next == NULL) {
		return true;
	}
	else {
		return false;
	}
}

int Link::Length() {
	Node *p = this->head->next;
	int length = 0;
	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length;
}

void Link::Delete(int index) {
	Node *p = this->head->next;
	if (isEmpty()) {
	}
	else {
		int i = 0;
		while (p != NULL && i != index - 1) {
			p = p->next;
			i++;
		}
		Node *h = p->next;
		p->next = h->next;
		delete h;
		this->count--;
	}
}

void Link::Insert(int index, int value) {
	Node *p = this->head->next;
	int i = 0;
	if (isEmpty()) {//空链表
		Node *pNew = new Node;
		pNew->data = value;
		pNew->next=NULL;
		this->head->next = pNew;
	}
	else {//非空链表
		while (p != NULL && i != index - 1) {
			p = p->next;
			i++;
		}
		Node *pNew = new Node;
		pNew->data = value;
		pNew->next = p->next;
		p->next = pNew;
		this->count++;
	}
}

int Link::Search_value(int index) {
	Node *p = head->next;
	int i = 0;
	while (p != NULL && i!=index) {
		p = p->next;
		i++;
	}
	if (p != NULL) {
		return p->data;
	}
	else {
		cout << "查找失败！" << endl;
	}
}

Node *Link::Search_node(int value) {
	Node *p = head->next;
	while (p != NULL && p->data != value) {
		p = p->next;
	}
	if (p != NULL) {
		return p;
	}
	else {
		return NULL;
	}
}

void Link::Foreach() {
	Node *p = this->head->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	Link a;
	for (int i = 0; i < 6; i++) {
		a.Insert(i, i);
	}
	a.Foreach();

	a.Delete(2);
	a.Foreach();
	system("pause");
	return 0;
}                             
