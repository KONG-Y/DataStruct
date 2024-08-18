#pragma once
#include<vector>
using namespace std;


//冒泡排序
void BubbleSort(vector<int>& nums)
{
	//每次循环，把当前最大的元素排到后面
	for (int i = 0; i < nums.size() - 1; i++) 
	{
		bool flag = false;
		for (int j = 0; j < nums.size() - 1 - i; j++) 
		{
			if (nums[j] > nums[j + 1]) 
			{
				flag = true;
				swap(nums[j], nums[j + 1]);
			}
		}
		if (!flag)
			break;
	}
}


//插入排序
void InsertSort(vector<int>& nums) 
{
	for (int i = 1; i < nums.size(); i++) 
	{
		//最新一个元素插入到前面排序好的数组
		for (int j = i; j > 0; j--) 
		{
			if (nums[j - 1] > nums[j])
				swap(nums[j - 1], nums[j]);
		}
	}
}

//选择排序
void SelectSort(vector<int>& nums) 
{
	for (int i = 0; i < nums.size(); i++) 
	{
		//每次循环，选出最小的元素放在前面
		int min = i;
		for (int j = i + 1; j < nums.size(); j++) 
		{
			if (nums[min] > nums[j])
				min = j;
		}
		if (min != i)
			swap(nums[min], nums[i]);
	}
}


//归并排序
void Merge(vector<int>& nums, int start, int mid, int end) 
{
	int left = start;
	int right = mid + 1;

	vector<int>aux(nums);

	for (int i = start; i <= end; i++) 
	{
		if (left > mid)nums[i] = aux[right++];
		else if (right > end)nums[i] = aux[left++];
		else if (aux[left] > aux[right])nums[i] = aux[right++];
		else  nums[i] = aux[left++];
	}
}


void MergeSort(vector<int>& nums, int start, int end) 
{
	if (start >= end)return;
	int mid = start + (end - start) / 2;

	MergeSort(nums, start, mid);
	MergeSort(nums, mid + 1, end);
	Merge(nums, start, mid, end);
}

//快速排序
int Partition(vector<int>& nums, int start, int end) 
{
	int left = start;
	int right = end + 1;
	int v = nums[start];
	while (1) 
	{
		while (nums[++left] <= v) { if (left == end)break; }
		while (nums[--right] >= v) { if (right == start)break; }
		if (left >= right)break;
		swap(nums[left], nums[right]);
	}
	swap(nums[start], nums[right]);
	return right;
}

void QuickSort(vector<int>& nums, int start, int end) 
{
	if (start >= end)return;
	int right = Partition(nums, start, end);

	QuickSort(nums, start, right-1);
	QuickSort(nums, right + 1, end);
}

//堆排序
void SiftDown(vector<int>& nums, int n, int i) 
{
	while (true) 
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int ma = i;
		if (l<n && nums[l] > nums[ma]) ma = l;
		if (r<n && nums[r] > nums[ma]) ma = r;
		if (ma == i)break;
		swap(nums[i], nums[ma]);
		i = ma;
	}
}

void HeapSort(vector<int>& nums) 
{
	for (int i = nums.size() / 2 - 1; i >= 0; --i)
	{
		SiftDown(nums, nums.size(), i);
	}

	for (int i = nums.size() - 1; i > 0; --i) 
	{
		swap(nums[0], nums[i]);
		SiftDown(nums, i, 0);
	}
}