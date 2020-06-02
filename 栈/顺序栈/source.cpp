#include<iostream>
using namespace std;
#define maxsize 5

class Stack {
public:
	Stack();
	bool isEmpty()const;
	bool isFull()const;
	void push(int data);
	void pop();
	void getTop();
private:
	int s_top;	    //栈顶位置
	int s_data[maxsize];//数据域
};

Stack::Stack() {
	s_top = -1;
}

//判断空栈
bool Stack::isEmpty()const {
	if (s_top == -1) {
		cout << "underflow" << endl;
		return true;
	}
	else {
		return false;
	}
}

//判断栈满
bool Stack::isFull()const {
	if (s_top+1 == maxsize) {
		cout << "overflow" << endl;
		return true;
	}
	else {
		return false;
	}
}

//获得栈顶元素
void Stack::getTop() {
	if (!isEmpty()) {
		cout<< s_data[s_top]<<endl;
	}
}

//进栈
void Stack::push(int data) {
	if (!isFull()) {
		s_data[++s_top] = data; //先移栈顶位置，再赋值
	}
}

//出栈
void Stack::pop() {
	if (!isEmpty()) {
		s_data[s_top--] = NULL; //先赋值，再移栈顶位置
	}
}


int main(){
	Stack a;
	cout << "------------进栈------------" << endl;
	for (int i = 0; i < 5; i++) {
		a.push(i);
		a.getTop();
	}
	cout <<"-------------出栈------------" << endl;
	for (int i = 0; i < 5; i++) {
		a.getTop();
		a.pop();
	}
	
	return 0;
}
