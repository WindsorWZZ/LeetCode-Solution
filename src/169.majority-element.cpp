/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // method 1
        // quickSort(nums, 0, nums.size() - 1);
        // return nums[nums.size() / 2];
        // method 2
        //return getMajorityElement(nums);

        //method 3
        ThreewaysQuickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() / 2];
    }

    // method 1: sort & return
    void quickSort(vector<int>& nums, int start, int end) {
        int mid = (start + end) / 2;
        sort3Elements(nums, start, mid, end);
        if (end - start <= 2) {
            return;
        }
        int pivot = nums[mid];
        swap(nums[mid], nums[end - 1]);
        int i = start + 1;
        int j = end - 2;
        while (i <= j) {
            while (nums[i] < pivot) ++i;
            while (nums[j] > pivot) --j;
            if (i <= j) {
                swap(nums[i++], nums[j--]);
            }
        }
        swap(nums[i], nums[end - 1]);
        if (i - start > 1) quickSort(nums, start, i - 1);
        if (end - i > 1) quickSort(nums, i + 1, end);
    }

    void sort3Elements(vector<int>& nums, int start, int mid, int end) {
        if (nums[start] > nums[mid]) swap(nums[start], nums[mid]);
        if (nums[mid] > nums[end]) swap(nums[mid], nums[end]);
        if (nums[start] > nums[mid]) swap(nums[start], nums[mid]);
    }

    // method 2: use hashmap to count
    int getMajorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (counter.find(num) != counter.end()) {
                counter[num]++;
            } else {
                counter[num] = 1;
            }
            if (counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }

    // method 3: 3 ways partition sorting
    void ThreewaysQuickSort(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int lt = start;
        int gt = end;
        int i = lt;
        while (i <= gt) {
            if (nums[i] > nums[lt]) {
                swap(nums[i], nums[gt--]);
            } else if (nums[i] < nums[lt]) {
                swap(nums[i++], nums[lt++]);
            } else {
                ++i;
            }
        }
        if (lt - start > 1) ThreewaysQuickSort(nums, start, lt - 1);
        if (end - gt > 1) ThreewaysQuickSort(nums, gt + 1, end);
    }
};
// @lc code=end

