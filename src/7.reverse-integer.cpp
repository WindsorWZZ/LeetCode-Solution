/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int flag = x > 0 ? 1 : -1;
        while (x != 0) {
            int num = -1 * abs(x % 10);
            x /= 10;
            if (res < -1 * abs(INT_MIN / 10) ||
            (res == -1 * abs(INT_MIN / 10) && num < -1 * abs(INT_MIN % 10))) {
                return 0;
            }
            res = 10 * res + num;
        }
        if (flag < 0) {
            return res;
        }
        if (res == INT_MIN) {
            return 0;
        }
        return -1 * res;
    }
};
// @lc code=end

