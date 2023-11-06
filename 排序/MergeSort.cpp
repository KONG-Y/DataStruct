#include<vector>
#include<iostream>
using namespace std;

/*-------------------------------------归并排序---------------------------------------*/
//时间复杂度：最好O(n)，最差O(nlogn)
//空间复杂度：O(n)
//稳定


//归并
void Merge(vector<int>& nums, int start, int mid, int end) {
	int left = start;	//左索引
	int right = mid + 1;  	//右索引
  
	vector<int>aux(nums); //辅助数组
	
  for (int i = start; i <= end; i++) {
		if	(left > mid)			nums[i] = aux[right++]; //左索引超出左范围
		else if (right > end)			nums[i] = aux[left++];	//右索引超出右范围
		else if (aux[left] > aux[right])	nums[i] = aux[right++];	//左索引元素大于右索引元素
		else					nums[i] = aux[left++];	//左索引元素小于右索引元素
	}
}

//排序
void MergeSort(vector<int>& nums, int start, int end) {
	if (start >= end)return;

	int mid = start + (end - start) / 2;	//中间索引
	MergeSort(nums, start, mid);		//左范围排序
	MergeSort(nums, mid + 1, end);		//右范围排序
	Merge(nums, start, mid, end);		//原地排序
}

int main() {
	vector<int>nums = { 5,7,6,0,4,11,3,4,88,65,4,22,1,33 };
	MergeSort(nums, 0, nums.size() - 1);
	for (auto i : nums)cout << i << ",";
	return 0;
}
