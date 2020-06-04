#include<iostream>
#define maxlen 10
using namespace std;
class list {
public:
	list();
	int Length()const;				//表的长度
	int Get_element(const int index)const;		//按序号查找元素，返回值
	int Locate(const int value)const;		//按之查找元素，返回序号
	void Insert(const int index, const int value);	//插入（在index位置前面插入）
	void Delete(const int index);			//删除
private:
	int data[maxlen];//数据域
	int count;   	 //表长度
};

list::list() {
	count = 0;
}

int list::Length()const {
	return count;
}


int list::Get_element(const int index)const {
	if (index<0 || index>count) {
		cout << "range_error";
	}
	else {
		return data[index];
	} 
}

void list::Insert(const int index, const int value) {
	if (count != maxlen) {						 //未溢出
		if (index >= 1 && index < Length() + 1) {		 //符合后移范围
			for (int i = Length() - 1; i >= index - 1; i--) {//位置后移（插在index位置前面，所以 i >= index - 1）
				data[i + 1] = data[i];
			}
		}
		data[index] = value;//插入数值
		count++;	    //表长度加1
		
	}
}

void list::Delete(const int index) {
	if (Length() != 0) {					  //未空
		if (index < Length()) {				  //符合删除范围
			for (int i = index; i < Length()-1; i++) {//位置前移
				data[i] = data[i + 1];
			}
			count--;//表长度减1
		}
	}
}

int main() {
	list a;
	for (int i = 0; i < 4; i++) {
		a.Insert(i, i);
	}
	for (int i = 0; i < a.Length(); i++) {
		cout << a.Get_element(i) << " ";
	}
	cout << endl;
	a.Delete(0);
	a.Delete(2);
	for (int i = 0; i < a.Length(); i++) {
		cout << a.Get_element(i) << " ";
	}

	system("pause");
	return 0;
}
