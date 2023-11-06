/*-------------------------------------选择排序---------------------------------------*/
//时间复杂度：O(n^2)
//不稳定

void SelectSort(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		int min = i;
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[min] > nums[j]) min = j;
		}
		if (min != i)swap(nums[min], nums[i]);
	}
}
