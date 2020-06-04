#include<iostream>
#define maxsize 10
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
		return p_data[(front+1)%maxsize];//队头没有元素，需加1
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
	q.append(1);
	cout << 1 << endl;//第1行直接打印
	int current;
	for (int i = 2; i <= 10; i++) {
		q.append(1);//行的第一个1进队
		cout << 1 << " ";
		for (int j = 0; j < i-2; j++) {//每行中间数值的运算
			current = q.serve();
			cout << current + q.get_front() <<" ";
			q.append(current + q.get_front());
			
		
		}
		q.append(q.serve());//行的最后1出队，并作为新行的最后1进队
		cout << 1 <<endl;
	}


	system("pause");
	return 0;

}
