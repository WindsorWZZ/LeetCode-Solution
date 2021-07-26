/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 0;
        int start = 0;
        int end = 0;
        while (end < nums.size()) {
            while (end < nums.size() && nums[end] == nums[start]) ++end;
            nums[pos++] = nums[start];
            start = end; 
        }
        return pos;
    }
};
// @lc code=end

