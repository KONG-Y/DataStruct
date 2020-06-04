#include<iostream>
#define maxsize 5
using namespace std;

class Queue {
public:
	Queue();
	bool isEmpty();
	bool isFull();
	void append(int value);//入队
	int get_front();	   //获得对头元素
	int serve();		   //出队
private:
	int q_data[maxsize];
	int front;
	int rear;

};

Queue::Queue() {
	front = 0;
	rear = -1;
}

bool Queue::isEmpty() {
	if (front > rear) {
		cout << "underflow" << endl;
		return true;
	}
	else {
		
		return false;
	}
}

bool Queue::isFull() {
	if (rear == maxsize-1) {
		cout << "overflow" << endl;
		return true;
	}
	else {
		return false;
	}
}

//获得队头元素
int Queue::get_front() {
	if (!isEmpty()) {
		return q_data[front];
	}
}

//入队
void Queue::append(int value) {
	if (!isFull()) {
		q_data[++rear] = value;
	}
}

//出队
int Queue::serve() {
	if (!isEmpty()) {
		return q_data[front++];
	}
}

int main() {
	Queue q;
	cout << "---------------入队------------" << endl;
	for (int i = 0; i < 5; i++) {
		q.append(i);
	}
	cout << "-----------------出队------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << q.serve() << endl;
	}
	return 0;
}
