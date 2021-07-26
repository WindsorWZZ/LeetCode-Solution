/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // if (nums.size() > 1) {
        //     quickSort(nums, 0, nums.size() - 1);
        // }
        vector<int> aux = vector<int>(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            aux[i] = nums[i];
        }
        mergeSort(nums, aux, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        int mid = (left + right) / 2;
        if (nums[left] > nums[mid]) swap(nums[left], nums[mid]);
        if (nums[mid] > nums[right]) swap(nums[mid], nums[right]);
        if (nums[left] > nums[mid]) swap(nums[left], nums[mid]);
        int pivot = nums[mid];
        swap(nums[mid], nums[right - 1]);
        if (right - left <= 2) {
            return;
        }
        int i = left + 1;
        int j = right - 2;
        while (i <= j) {
            while (nums[i] < pivot) ++i;
            while (nums[j] > pivot) --j;
            if (i <= j) {
                swap(nums[i], nums[j]);
                ++i; --j;
            }
        }
        swap(nums[i], nums[right - 1]);
        if (i - left > 1) quickSort(nums, left, i - 1);
        if (right - i > 1) quickSort(nums, i + 1, right);
    }

    void mergeSort(vector<int>& nums, vector<int>& aux, int left, int right) {
        if (left < right) {
            mergeSort(aux, nums, left, (left + right) / 2);
            mergeSort(aux, nums, (left + right) / 2 + 1, right);
        } else {
            return;
        }
        merge(aux, nums, left, (left + right) / 2, right);
    }

    void merge(vector<int>& nums, vector<int>& aux, int left, int mid, int right) {
        int pos = left;
        int pos_1 = left;
        int pos_2 = mid + 1;
        while (pos_1 <= mid || pos_2 <= right) {
            if (pos_1 > mid) {
                aux[pos++] = nums[pos_2++];
            } else if (pos_2 > right) {
                aux[pos++] = nums[pos_1++];
            } else if (nums[pos_1] <= nums[pos_2]) {
                aux[pos++] = nums[pos_1++];
            } else {
                aux[pos++] = nums[pos_2++];
            }
        }
    }
};
// @lc code=end

