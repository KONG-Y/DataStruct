/*-------------------------------------冒泡排序---------------------------------------*/
//时间复杂度：最好O(n),最坏和平均O（n^2）
//稳定


void BubbleSort(vector<int>& nums) {
	for (int i = 0; i < nums.size() - 1; i++) {
		for (int j = 0; j < nums.size() - 1 - i; j++) {
			if (nums[j] > nums[j + 1]) {
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}
