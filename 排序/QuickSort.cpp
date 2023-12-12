#include<vector>
#include<iostream>
using namespace std;

/*-------------------------------------快速排序---------------------------------------*/
//时间复杂度：最好和平均O(nlogn)，最坏O(n^2)
//空间复杂度：递归使用栈帧空间，O(n)
//不稳定

//获得切分索引
int Partition(vector<int>& nums, int start, int end) {
	int left = start;	//左指针
	int right = end + 1;	//右指针
	int v = nums[start];	//切分元素

	while (1) {
		while (nums[++left] <= v) { if (left == end)break; }	//小于等于切分元素，左指针向右移动
		while (nums[--right] >= v) { if (right == start)break; }//大于等于切分元素，右指针向左移动
		if (left >= right)break;				//左指针大于等于右指针，退出循环
		swap(nums[left], nums[right]);				//不符合规则的左指针元素和右指针元素进行交换。
	}
	swap(nums[start], nums[right]);//切分元素放在正确位置
	return right;
}

void QuickSort(vector<int>& nums, int start, int end) {
	if (start >= end)return;
	int right = Partition(nums, start, end);

	QuickSort(nums, start, right - 1);
	QuickSort(nums, right + 1, end);
}
