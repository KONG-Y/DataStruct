#include<iostream>
#define maxsize 5
using namespace std;

class CirQueue {
public:
	CirQueue();
	bool isEmpty();
	bool isFull();
	int serve();
	void append(int value);
	int get_front();
private:
	int front;
	int rear;
	int p_data[maxsize];
};

CirQueue::CirQueue() {
	front = 0;
	rear = 0;
}

bool CirQueue::isEmpty() {
	if ( front == rear) {

		return true;
	}
	else {
		return false;
	}
}

bool CirQueue::isFull() {
	if ( (rear+1)%maxsize == front) {//队尾指针下一步等于队头（牺牲一个位置来表示“满”状态）
		cout << "overflow" << endl;
		return true;
	}
	else {
		return false;
	}
}

//获得队头元素
int CirQueue::get_front() {
	if (!isEmpty()) {
		front = (front + 1) % maxsize;//队头没有元素，需加1
		return p_data[front];
	}
}

//入队
void CirQueue::append(int value) {
	if (!isFull()) {
		rear = (rear + 1) % maxsize;//队尾指向最后元素
		p_data[rear]=value;
	}
}

//出队
int CirQueue::serve() {
	if (!isEmpty()) {
		front = (front + 1) % maxsize;//队头没有元素，需加1
		return p_data[front];
	}
}

int main() {
	CirQueue q;
	cout << "-----------------入队---------------" << endl;
	for (int i = 0; i < 4; i++) {
		q.append(i);
	}
	cout << "-----------------出队---------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << q.serve() << endl;
	}

	system("pause");
	return 0;

}
